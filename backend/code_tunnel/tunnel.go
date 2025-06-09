package main

import (
    "context"
    "encoding/json"
    "fmt"
    "io"
    "log"
    "net/http"
    "os"
    "os/exec"
    "path/filepath"
    "sync"
    "time"
    "golang.org/x/time/rate"
)

// Config holds the application configuration
type Config struct {
    Port            string        `json:"port"`
    Timeout         time.Duration `json:"timeout"`
    MaxFileSize     int64         `json:"maxFileSize"`
    DockerImage     string        `json:"dockerImage"`
    RateLimit       int           `json:"rateLimit"`
    RateBurst       int           `json:"rateBurst"`
    AllowedOrigins  []string      `json:"allowedOrigins"`
    EnableAuth      bool          `json:"enableAuth"`
    AuthToken       string        `json:"authToken"`
}

// DefaultConfig returns the default configuration
func DefaultConfig() Config {
    return Config{
        Port:           ":8080",
        Timeout:        7 * time.Second,
        MaxFileSize:    1 << 20, // 1MB
        DockerImage:    "alphastar59/cookie:latest",
        RateLimit:      10,      // requests per second
        RateBurst:      20,      // burst size
        AllowedOrigins: []string{"*"},
        EnableAuth:     false,
        AuthToken:      "",
    }
}

// LoadConfig loads configuration from a JSON file
func LoadConfig(filename string) (Config, error) {
    config := DefaultConfig()
    
    if filename != "" {
        file, err := os.Open(filename)
        if err != nil {
            return config, fmt.Errorf("error opening config file: %v", err)
        }
        defer file.Close()

        decoder := json.NewDecoder(file)
        if err := decoder.Decode(&config); err != nil {
            return config, fmt.Errorf("error decoding config file: %v", err)
        }
    }
    
    return config, nil
}

// Server represents the HTTP server
type Server struct {
    config     Config
    limiter    *rate.Limiter
    logger     *log.Logger
    mu         sync.Mutex
    activeRuns int
}

// NewServer creates a new server instance
func NewServer(config Config) *Server {
    return &Server{
        config:  config,
        limiter: rate.NewLimiter(rate.Limit(config.RateLimit), config.RateBurst),
        logger:  log.New(os.Stdout, "[SERVER] ", log.LstdFlags|log.Lshortfile),
    }
}

// validateCode performs basic code validation
func (s *Server) validateCode(code []byte) error {
    if len(code) == 0 {
        return fmt.Errorf("empty code")
    }
    if len(code) > int(s.config.MaxFileSize) {
        return fmt.Errorf("code size exceeds limit of %d bytes", s.config.MaxFileSize)
    }
    // Add more validation as needed
    return nil
}

// checkAuth validates the authentication token
func (s *Server) checkAuth(r *http.Request) error {
    if !s.config.EnableAuth {
        return nil
    }
    
    token := r.Header.Get("Authorization")
    if token == "" {
        return fmt.Errorf("missing authorization token")
    }
    
    if token != s.config.AuthToken {
        return fmt.Errorf("invalid authorization token")
    }
    
    return nil
}

// checkOrigin validates the request origin
func (s *Server) checkOrigin(r *http.Request) error {
    if len(s.config.AllowedOrigins) == 1 && s.config.AllowedOrigins[0] == "*" {
        return nil
    }
    
    origin := r.Header.Get("Origin")
    for _, allowed := range s.config.AllowedOrigins {
        if origin == allowed {
            return nil
        }
    }
    
    return fmt.Errorf("unauthorized origin: %s", origin)
}

func (s *Server) runHandler(w http.ResponseWriter, r *http.Request) {
    // Check rate limit
    if !s.limiter.Allow() {
        http.Error(w, "Rate limit exceeded", http.StatusTooManyRequests)
        return
    }

    // Check authentication
    if err := s.checkAuth(r); err != nil {
        s.logger.Printf("Authentication error: %v", err)
        http.Error(w, "Unauthorized", http.StatusUnauthorized)
        return
    }

    // Check origin
    if err := s.checkOrigin(r); err != nil {
        s.logger.Printf("Origin error: %v", err)
        http.Error(w, "Unauthorized origin", http.StatusForbidden)
        return
    }

    // Limit concurrent runs
    s.mu.Lock()
    if s.activeRuns >= 10 {
        s.mu.Unlock()
        http.Error(w, "Server is busy", http.StatusServiceUnavailable)
        return
    }
    s.activeRuns++
    s.mu.Unlock()
    defer func() {
        s.mu.Lock()
        s.activeRuns--
        s.mu.Unlock()
    }()

    // Limit body size
    r.Body = http.MaxBytesReader(w, r.Body, s.config.MaxFileSize)

    // Read uploaded code
    code, err := io.ReadAll(r.Body)
    if err != nil {
        s.logger.Printf("Error reading code: %v", err)
        http.Error(w, "Failed to read code", http.StatusBadRequest)
        return
    }

    // Validate code
    if err := s.validateCode(code); err != nil {
        s.logger.Printf("Code validation error: %v", err)
        http.Error(w, err.Error(), http.StatusBadRequest)
        return
    }

    // Save to file
    filename := "lang.cook"
    err = os.WriteFile(filename, code, 0644)
    if err != nil {
        s.logger.Printf("Error saving file: %v", err)
        http.Error(w, "Failed to save file", http.StatusInternalServerError)
        return
    }

    // Get absolute path
    absPath, err := filepath.Abs(".")
    if err != nil {
        s.logger.Printf("Error getting absolute path: %v", err)
        http.Error(w, "Failed to get current directory", http.StatusInternalServerError)
        return
    }

    // Create context with timeout
    ctx, cancel := context.WithTimeout(context.Background(), s.config.Timeout)
    defer cancel()

    // Prepare docker run command
    cmd := exec.CommandContext(ctx, "docker", "run", "--rm", "-v",
        fmt.Sprintf("%s/%s:/cookie_dir/lang.cook", absPath, filename),
        s.config.DockerImage)

    // Execute
    start := time.Now()
    out, err := cmd.CombinedOutput()
    duration := time.Since(start)

    // Log execution details
    s.logger.Printf("Code execution completed in %v", duration)
    if err != nil {
        s.logger.Printf("Execution error: %v\nOutput: %s", err, out)
        http.Error(w, fmt.Sprintf("Error: %s\nOutput:\n%s", err, out), http.StatusInternalServerError)
        return
    }

    // Set CORS headers
    w.Header().Set("Access-Control-Allow-Origin", "*")
    w.Header().Set("Access-Control-Allow-Methods", "POST, OPTIONS")
    w.Header().Set("Access-Control-Allow-Headers", "Content-Type, Authorization")
    w.Header().Set("Content-Type", "text/plain")
    
    // Send output
    w.Write(out)
}

func main() {
    // Load configuration
    config, err := LoadConfig("config.json")
    if err != nil {
        log.Printf("Warning: Using default configuration: %v", err)
    }

    // Create and start server
    server := NewServer(config)
    
    // Handle CORS preflight requests
    http.HandleFunc("/run", func(w http.ResponseWriter, r *http.Request) {
        if r.Method == "OPTIONS" {
            w.Header().Set("Access-Control-Allow-Origin", "*")
            w.Header().Set("Access-Control-Allow-Methods", "POST, OPTIONS")
            w.Header().Set("Access-Control-Allow-Headers", "Content-Type, Authorization")
            w.WriteHeader(http.StatusOK)
            return
        }
        server.runHandler(w, r)
    })

    // Start server
    log.Printf("Server starting on http://localhost%s", config.Port)
    log.Printf("Configuration: %+v", config)
    log.Fatal(http.ListenAndServe(config.Port, nil))
}
