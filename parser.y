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

/* Helper: Concatenate three strings */
char* concat3(const char* s1, const char* s2, const char* s3) {
    int len = strlen(s1) + strlen(s2) + strlen(s3) + 1;
    char* result = malloc(len);
    if (!result) { fprintf(stderr, "Out of memory\n"); exit(1); }
    strcpy(result, s1);
    strcat(result, s2);
    strcat(result, s3);
    return result;
}
%}

%union {
    char* str;
}

%token INT PRINT LOOP ASSIGN SEMICOLON LPAREN RPAREN LBRACE RBRACE
%token <str> NUMBER IDENTIFIER
%token PLUS MINUS MULTIPLY DIVIDE  // Added DIVIDE token

/***** Added operator precedence declaration *****/
%left PLUS MINUS
%left MULTIPLY DIVIDE  // Multiplication and division have higher precedence

%type <str> expression primary

%%

program:
    statements
    ;

statements:
    statement
    | statements statement
    ;

statement:
    INT IDENTIFIER ASSIGN expression SEMICOLON {
        printf("int %s = %s;\n", $2, $4);
        symbol_table[symbol_count].name = strdup($2);
        symbol_count++;
        free($2);
        free($4);
    }
    | PRINT LPAREN expression RPAREN SEMICOLON {
        int found = 0;
        /* If the expression is a simple identifier, verify it exists */
        for (int i = 0; i < symbol_count; i++) {
            if (strcmp(symbol_table[i].name, $3) == 0) found = 1;
        }
        if (!found) yyerror("Undefined variable");
        printf("std::cout << %s << \"\\n\";\n", $3);
        free($3);
    }
    // Loop with mid-rule actions
    | LOOP NUMBER LBRACE {
        printf("for (int _loop = 0; _loop < %s; _loop++) {\n", $2);
        free($2);
    }
    statements RBRACE {
        printf("}\n");
    }
    ;

expression:
      expression PLUS expression {
          $$ = concat3($1, " + ", $3);
          free($1);
          free($3);
      }
    | expression MINUS expression {
          $$ = concat3($1, " - ", $3);
          free($1);
          free($3);
      }
    | expression MULTIPLY expression {
          $$ = concat3($1, " * ", $3);
          free($1);
          free($3);
      }
    | expression DIVIDE expression {  // Added division handling
          $$ = concat3($1, " / ", $3);
          free($1);
          free($3);
      }
    | primary {
          $$ = $1;
      }
    ;

primary:
      NUMBER           { $$ = $1; }
    | IDENTIFIER       { $$ = $1; }
    | LPAREN expression RPAREN {
          $$ = concat3("(", $2, ")");
          free($2);
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
