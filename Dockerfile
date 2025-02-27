# Use Ubuntu 22.04 as the base image
FROM ubuntu:22.04

# Disable interactive prompts during package installation
ENV DEBIAN_FRONTEND=noninteractive

# Install required packages with IPv4 forced (this helps avoid mirror issues)
RUN apt-get update && apt-get install -y --fix-missing -o Acquire::ForceIPv4=true \
    build-essential \
    clang \
    llvm \
    llvm-dev \
    flex \
    bison \
    curl \
    && rm -rf /var/lib/apt/lists/*

# Set the working directory inside the container
WORKDIR /goofy

# Copy your entire project into the container
COPY . .

# Build your compiler using your manual build commands
RUN gcc -shared -fPIC runtime.c -o libruntime.so && \
    bison -d parser.y && \
    flex lexer.l && \
    gcc -c ast.c -o ast.o && \
    gcc -c parser.tab.c -o parser.tab.o && \
    gcc -c lex.yy.c -o lex.yy.o && \
    gcc -c runtime.c -o runtime.o && \
    g++ -c codegen.cpp -o codegen.o $(llvm-config --cxxflags) && \
    g++ ast.o parser.tab.o lex.yy.o codegen.o runtime.o -o compiler $(llvm-config --ldflags --libs core)

# By default, run the compiler on "lang.li", produce output.ll, and run it with lli
CMD cat lang.li | ./compiler > output.ll && lli -load ./libruntime.so output.ll
