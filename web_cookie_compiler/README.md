# Web-based Cookie Language Compiler

This is a web-based version of the Cookie programming language compiler that runs entirely in the browser using WebAssembly

## Prerequisites

- Go (https://golang.org/dl/)
- Emscripten (installed via emsdk)

## Installing Emscripten

Manually install Emscripten SDK:
```
git clone https://github.com/emscripten-core/emsdk.git
cd emsdk
```
To Activate: 

Linux/MacOS:
```
./emsdk install latest 
./emsdk activate latest
source ./emsdk_env.sh 
```

Windows:
```
.\emsdk install latest
.\emsdk activate latest
.\emsdk_env.ps1
```

Important:
Activating Emscripten (emsdk_env.ps1 or emsdk_env.sh) is session-based — it only affects the current terminal session.

You will need to run this command again in any new terminal session where you want to use emcc.


##Running the Server

1. Open a new terminal in the directory where server.go is located.

2.Activate Emscripten in this terminal:
   ```bash
   ..\emsdk\emsdk_env.ps1   # Windows PowerShell
   ../emsdk/emsdk_env.sh    # Linux/macOS
   ```

3. Run the Go server:
   ```bash
   go run server.go
   ```

4. Open your browser to `http://localhost:8000`


## Project Structure

- `index.html` — Web interface that compiles and runs Cookie code in the browser via WebAssembly and JS.
- `public/` - Static assets and WASM files
- `server.go` — Go web server that compiles Cookie source code to WebAssembly via `emcc` and serves the frontend and compiled output.
- `emsdk/` — Emscripten SDK and toolchain files.
