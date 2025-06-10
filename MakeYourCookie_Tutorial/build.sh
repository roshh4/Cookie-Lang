#!/bin/bash

set -e  # Exit on error

echo "Compiling runtime..."
gcc -shared -fPIC runtime.c -o libruntime.so

echo "Generating parser..."
bison -d parser.y

echo "Generating lexer..."
flex lexer.l

echo "Compiling components..."
gcc -c ast.c -o ast.o
gcc -c parser.tab.c -o parser.tab.o
gcc -c lex.yy.c -o lex.yy.o
gcc -c runtime.c -o runtime.o
g++ -c codegen.cpp -o codegen.o $(llvm-config --cxxflags)

echo "Linking..."
g++ ast.o parser.tab.o lex.yy.o codegen.o runtime.o -o compiler $(llvm-config --ldflags --libs core) -lfl

echo "Cleaning up intermediate files..."
rm -f ast.o parser.tab.c parser.tab.h parser.tab.o lex.yy.c lex.yy.o codegen.o runtime.o libruntime.so

echo "Build complete!" 