# Web-based Cookie Language Compiler

This is a web-based version of the Cookie programming language compiler that runs entirely in the browser using WebAssembly.

## Prerequisites

- Node.js (v16 or later)
- npm or yarn
- Emscripten (will be installed by the setup script)
- Flex and Bison

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

## Development

- The web interface uses React and Monaco Editor
- The compiler is compiled to WebAssembly using Emscripten
- The project uses Vite for fast development and building

## Building for Production

```bash
npm run build
```

The built files will be in the `dist` directory.

## Project Structure

- `src/` - React components and TypeScript code
- `public/` - Static assets and WASM files
- `build/` - Temporary build directory for WASM compilation

## Features

- Syntax highlighting for Cookie language
- Real-time compilation
- WebAssembly-based execution
- Modern web interface 