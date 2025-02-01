%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
} Symbol;

Symbol symbol_table[100];
int symbol_count = 0;

extern int yylex();
void yyerror(const char *s);
%}

%union {
    int num;
    char* id;
}

%token INT PRINT LOOP ASSIGN SEMICOLON LPAREN RPAREN LBRACE RBRACE
%token <num> NUMBER
%token <id> IDENTIFIER

%%

program:
    statements
    ;

statements:
    statement
    | statements statement
    ;

statement:
    INT IDENTIFIER ASSIGN NUMBER SEMICOLON {
        printf("int %s = %d;\n", $2, $4);
        symbol_table[symbol_count].name = strdup($2);
        symbol_count++;
    }
    | PRINT LPAREN IDENTIFIER RPAREN SEMICOLON {
        int found = 0;
        for (int i = 0; i < symbol_count; i++) {
            if (strcmp(symbol_table[i].name, $3) == 0) found = 1;
        }
        if (!found) yyerror("Undefined variable");
        printf("std::cout << %s << \"\\n\";\n", $3);
    }
    // Loop with mid-rule actions
    | LOOP NUMBER LBRACE {
        printf("for (int _loop = 0; _loop < %d; _loop++) {\n", $2); // Print loop start
    } 
    statements RBRACE {
        printf("}\n"); // Print loop end
    }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    printf("#include <iostream>\n\n");
    printf("int main() {\n");
    yyparse();
    printf("return 0;\n");
    printf("}\n");
    return 0;
}