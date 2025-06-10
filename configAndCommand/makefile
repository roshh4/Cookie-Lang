.PHONY: compile run remove

# Set compilers
CC = gcc
CXX = g++

# Specify LLVM include directory explicitly (adjust if needed)
LLVM_INCLUDE = -I/opt/homebrew/Cellar/llvm/19.1.7/include

# Get LLVM flags from llvm-config
LLVM_CXXFLAGS := $(shell llvm-config --cxxflags)
LLVM_LDFLAGS := $(shell llvm-config --ldflags --libs --link-static core)

# Compiler flags:
# For C files:
CFLAGS = -O2 -Wall
# For C++ files:
CXXFLAGS = -O2 -Wall $(LLVM_INCLUDE) $(LLVM_CXXFLAGS)

# Linker flags:
LDFLAGS = $(LLVM_LDFLAGS)

# Object files list
OBJS = ast.o parser.tab.o lex.yy.o runtime.o codegen.o

goofy:
	@gcc -shared -fPIC runtime.c -o libruntime.so
	@bison -d parser.y
	@flex lexer.l
	@gcc -c ast.c -o ast.o
	@gcc -c parser.tab.c -o parser.tab.o
	@gcc -c lex.yy.c -o lex.yy.o
	@gcc -c runtime.c -o runtime.o
	@g++ -c codegen.cpp -o codegen.o $(LLVM_CXXFLAGS) $(LLVM_INCLUDE)
	@g++ ast.o parser.tab.o lex.yy.o codegen.o runtime.o -o compiler $(LLVM_LDFLAGS)

run:
	@cat lang.li | ./compiler > output.ll
	@lli -load ./libruntime.so output.ll

remove:
	@rm -f ast.o parser.tab.c parser.tab.h parser.tab.o lex.yy.c lex.yy.o codegen.o compiler output.ll libruntime.so
