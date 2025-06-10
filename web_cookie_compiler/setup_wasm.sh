#!/bin/bash

# Install Emscripten
if [ ! -d "emsdk" ]; then
    git clone https://github.com/emscripten-core/emsdk.git
fi
cd emsdk
./emsdk install latest
./emsdk activate latest
source ./emsdk_env.sh

# Go back to project root
cd ..

# Create a build directory
mkdir -p build
cd build

# Compile to WebAssembly
emcc -o hello.js \
    ../src/hello.c \
    -s WASM=1 \
    -s EXPORTED_FUNCTIONS='["_main", "_say_hello"]' \
    -s ENVIRONMENT=web \
    -s MODULARIZE=1 \
    -s EXPORT_NAME="HelloModule" \
    -s EXPORT_ES6=1 \
    -s USE_ES6_IMPORT_META=1 \
    -s EXPORTED_RUNTIME_METHODS='["ccall", "cwrap"]' \
    -s NO_EXIT_RUNTIME=1 \
    -O3

# Create public directory if it doesn't exist
mkdir -p ../public

# Move the output files to the public directory
mv hello.js hello.wasm ../public/ 