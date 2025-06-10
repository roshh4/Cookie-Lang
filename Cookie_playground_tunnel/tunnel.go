package main

import (
    "fmt"
    "io"
    "log"
    "net/http"
    "os"
    "os/exec"
    "path/filepath"
    "encoding/json"
)

type CodePayload struct {
    Code string `json:"code"`
}

func main() {
    // Create a simple HTTP server
    http.HandleFunc("/run", func(w http.ResponseWriter, r *http.Request) {
        // Set CORS headers
        w.Header().Set("Access-Control-Allow-Origin", "https://alphastar-avi.github.io")
        w.Header().Set("Access-Control-Allow-Methods", "POST, OPTIONS")
        w.Header().Set("Access-Control-Allow-Headers", "Content-Type")

        // Handle preflight OPTIONS requests
        if r.Method == http.MethodOptions {
            w.WriteHeader(http.StatusOK)
            return
        }

        // Only allow POST requests
        if r.Method != http.MethodPost {
            http.Error(w, "Only POST method is allowed", http.StatusMethodNotAllowed)
            return
        }

        var code []byte
        var err error

        // Check if this is a multipart form (file upload)
        if r.Header.Get("Content-Type") == "multipart/form-data" {
            // Parse the multipart form
            err = r.ParseMultipartForm(10 << 20) // 10 MB max
            if err != nil {
                http.Error(w, "Failed to parse form", http.StatusBadRequest)
                return
            }

            // Get the file from the form
            file, _, err := r.FormFile("file")
            if err != nil {
                http.Error(w, "Failed to get file from form", http.StatusBadRequest)
                return
            }
            defer file.Close()

            // Read the file content
            code, err = io.ReadAll(file)
            if err != nil {
                http.Error(w, "Failed to read file", http.StatusInternalServerError)
                return
            }
        } else if r.Header.Get("Content-Type") == "application/json" {
            var payload CodePayload
            err = json.NewDecoder(r.Body).Decode(&payload)
            if err != nil {
                http.Error(w, "Failed to decode JSON payload", http.StatusBadRequest)
                return
            }
            code = []byte(payload.Code)
        } else {
            // Read the code directly from request body (fallback for text/plain)
            code, err = io.ReadAll(r.Body)
            if err != nil {
                http.Error(w, "Failed to read code", http.StatusBadRequest)
                return
            }
            defer r.Body.Close()
        }

        // Save the code to a file
        err = os.WriteFile("cookie.cook", code, 0644)
        if err != nil {
            http.Error(w, "Failed to save code", http.StatusInternalServerError)
            return
        }

        // Get the absolute path of the current directory
        absPath, err := filepath.Abs(".")
        if err != nil {
            http.Error(w, "Failed to get current directory", http.StatusInternalServerError)
            return
        }

        // Run the code in Docker
        cmd := exec.Command("docker", "run", "--rm", "-i", "-v",
            fmt.Sprintf("%s/cookie.cook:/cookie_dir/lang.cook", absPath),
            "alphastar59/cookie:latest")

        // Capture the output
        output, err := cmd.CombinedOutput()
        if err != nil {
            http.Error(w, fmt.Sprintf("Execution error: %v\nOutput: %s", err, output), http.StatusInternalServerError)
            return
        }

        // Send the output back to the client
        w.Header().Set("Content-Type", "text/plain")
        w.Write(output)
    })

    // Start the server
    port := ":8080"
    fmt.Printf("Server starting on port %s...\n", port)
    fmt.Println("Use ngrok to expose this port to the internet")
    fmt.Println("Example: ngrok http 8080")
    
    if err := http.ListenAndServe(port, nil); err != nil {
        log.Fatal(err)
    }
}
