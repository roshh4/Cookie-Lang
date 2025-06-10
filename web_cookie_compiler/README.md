# Web-based Cookie Language Compiler

This is a web-based version of the Cookie programming language compiler that runs entirely in the browser using WebAssembly

## Prerequisites

- Node.js 
- Emscripten (will be installed by the setup script)

## Setup

1. Install dependencies:
   ```bash
   npm install
   ```

2. Run the WASM setup script:
   ```bash
   ./setup_wasm.sh
   ```

3. Start the development server:
   ```bash
   npm start
   ```

4. Open your browser to `http://localhost:5173`


The compiler is compiled to WebAssembly using Emscripten


## Building for Production

```bash
npm run build
```

## Project Structure

- `src/` - React components and TypeScript code
- `public/` - Static assets and WASM files
- `build/` - Temporary build directory for WASM compilation
