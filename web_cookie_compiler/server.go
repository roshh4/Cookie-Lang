package main

import (
	"bytes"
	"encoding/json"
	"io"
	"io/ioutil"
	"log"
	"net/http"
	"os"
	"os/exec"
	"path/filepath"
)

type CompileRequest struct {
	Code string `json:"code"`
}

type CompileResponse struct {
	Status  string `json:"status"`
	Message string `json:"message,omitempty"`
}

func compileHandler(w http.ResponseWriter, r *http.Request) {
	if r.Method != http.MethodPost {
		http.Error(w, "Method not allowed", http.StatusMethodNotAllowed)
		return
	}

	var req CompileRequest
	if err := json.NewDecoder(r.Body).Decode(&req); err != nil {
		http.Error(w, "Invalid JSON", http.StatusBadRequest)
		return
	}

	tempDir, err := ioutil.TempDir("", "compile")
	if err != nil {
		http.Error(w, "Failed to create temp dir", http.StatusInternalServerError)
		return
	}
	defer os.RemoveAll(tempDir)

	cFile := filepath.Join(tempDir, "cookie.c")
	if err := ioutil.WriteFile(cFile, []byte(req.Code), 0644); err != nil {
		http.Error(w, "Failed to write C file", http.StatusInternalServerError)
		return
	}

	cmd := exec.Command("emcc",
		"-o", "cookie.js",
		cFile,
		"-s", "WASM=1",
		"-s", "EXPORTED_FUNCTIONS=[\"_main\"]",
		"-s", "ENVIRONMENT=web",
		"-s", "MODULARIZE=1",
		"-s", "EXPORT_NAME=HelloModule",
		"-s", "EXPORT_ES6=1",
		"-s", "USE_ES6_IMPORT_META=1",
		"-s", "EXPORTED_RUNTIME_METHODS=[\"ccall\",\"cwrap\"]",
		"-s", "NO_EXIT_RUNTIME=1",
		"-O3",
	)
	cmd.Dir = tempDir
	var stderr bytes.Buffer
	cmd.Stderr = &stderr
	if err := cmd.Run(); err != nil {
		log.Println("emcc error:", err)
		log.Println("emcc stderr:", stderr.String())
		w.WriteHeader(http.StatusInternalServerError)
		json.NewEncoder(w).Encode(CompileResponse{Status: "error", Message: stderr.String()})
		return
	}

	if err := os.MkdirAll("public", 0755); err != nil {
		http.Error(w, "Failed to create public dir", http.StatusInternalServerError)
		return
	}

	for _, ext := range []string{"js", "wasm"} {
		src := filepath.Join(tempDir, "cookie."+ext)
		dst := filepath.Join("public", "cookie."+ext)
		if err := copyFile(src, dst); err != nil {
			http.Error(w, "Failed to copy output files", http.StatusInternalServerError)
			return
		}
	}

	w.Header().Set("Content-Type", "application/json")
	json.NewEncoder(w).Encode(CompileResponse{Status: "success"})
}

func copyFile(src, dst string) error {
	in, err := os.Open(src)
	if err != nil {
		return err
	}
	defer in.Close()
	out, err := os.Create(dst)
	if err != nil {
		return err
	}
	defer out.Close()
	_, err = io.Copy(out, in)
	return err
}

func main() {
	http.HandleFunc("/compile", compileHandler)
	fs := http.FileServer(http.Dir("."))
	http.Handle("/", fs)
	log.Println("Server running on :8000")
	log.Fatal(http.ListenAndServe(":8000", nil))
}
