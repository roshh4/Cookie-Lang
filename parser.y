%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include "ast.h"

// Global pointer to the entire program AST.
ProgramAST *TheAST = new ProgramAST();

extern int yylex();
void yyerror(const char *s) { fprintf(stderr, "Error: %s\n", s); }
%}

%union {
    int num;                 // for NUMBER tokens
    char* id;                // for IDENTIFIER tokens
    ExprAST* expr;           // for expressions
    StmtAST* stmt;           // for statements
    std::vector<StmtAST*>* stmtList;  // for lists of statements
}

%token INT PRINT LOOP ASSIGN SEMICOLON LPAREN RPAREN LBRACE RBRACE
%token PLUS MINUS MULTIPLY DIVIDE
%token <num> NUMBER
%token <id> IDENTIFIER

%left PLUS MINUS
%left MULTIPLY DIVIDE

%type <expr> expression primary
%type <stmt> statement
%type <stmtList> statements

%%

program:
    statements {
        for (StmtAST *S : *$1)
            TheAST->Statements.push_back(S);
        delete $1;
    }
    ;

statements:
    /* empty */ { $$ = new std::vector<StmtAST*>(); }
    | statements statement { $$ = $1; $$->push_back($2); }
    ;

statement:
    INT IDENTIFIER ASSIGN expression SEMICOLON {
        $$ = new VarDeclAST(std::string($2), $4);
        free($2);
    }
    | PRINT LPAREN expression RPAREN SEMICOLON {
        $$ = new PrintAST($3);
    }
    | LOOP expression LBRACE statements RBRACE {
        $$ = new LoopAST($2, *$4);
        delete $4;
    }
    ;

expression:
      expression PLUS expression {
          $$ = new BinaryExprAST('+', $1, $3);
      }
    | expression MINUS expression {
          $$ = new BinaryExprAST('-', $1, $3);
      }
    | expression MULTIPLY expression {
          $$ = new BinaryExprAST('*', $1, $3);
      }
    | expression DIVIDE expression {
          $$ = new BinaryExprAST('/', $1, $3);
      }
    | primary { $$ = $1; }
    ;

primary:
      NUMBER { $$ = new NumberExprAST($1); }
    | IDENTIFIER { $$ = new VariableExprAST(std::string($1)); free($1); }
    | LPAREN expression RPAREN { $$ = $2; }
    ;

%%

int main() {
    if(yyparse() == 0) {
        if (TheAST->codegen() == nullptr) {
            fprintf(stderr, "Error generating IR\n");
            return 1;
        }
        TheModule->print(llvm::outs(), nullptr);
        return 0;
    }
    return 1;
}
