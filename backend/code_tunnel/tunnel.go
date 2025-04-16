package main

import (
    "context"
    "fmt"
    "io"
    "log"
    "net/http"
    "os"
    "os/exec"
    "path/filepath"
    "time"
)

func runHandler(w http.ResponseWriter, r *http.Request) {
    // Limit body size (optional: protect against large uploads)
    r.Body = http.MaxBytesReader(w, r.Body, 1<<20) // 1MB

    // Read uploaded code
    code, err := io.ReadAll(r.Body)
    if err != nil {
        http.Error(w, "Failed to read code", http.StatusBadRequest)
        return
    }

    // Save to file
    filename := "lang.cook"
    err = os.WriteFile(filename, code, 0644)
    if err != nil {
        http.Error(w, "Failed to save file", http.StatusInternalServerError)
        return
    }

    // Get absolute path to mount volume correctly
    absPath, err := filepath.Abs(".")
    if err != nil {
        http.Error(w, "Failed to get current directory", http.StatusInternalServerError)
        return
    }

    // Create a context with timeout (10 seconds)
    ctx, cancel := context.WithTimeout(context.Background(), 10*time.Second)
    defer cancel()

    // Prepare docker run command
    cmd := exec.CommandContext(ctx, "docker", "run", "--rm", "-v",
        fmt.Sprintf("%s/%s:/cookie_dir/lang.cook", absPath, filename),
        "alphastar59/cookie:latest")

    // Execute
    out, err := cmd.CombinedOutput()
    if err != nil {
        http.Error(w, fmt.Sprintf("Error: %s\nOutput:\n%s", err, out), http.StatusInternalServerError)
        return
    }

    // Send output
    w.Header().Set("Content-Type", "text/plain")
    w.Write(out)
}

func main() {
    http.HandleFunc("/run", runHandler)
    fmt.Println("Server listening on http://localhost:8080")
    log.Fatal(http.ListenAndServe(":8080", nil))
}
