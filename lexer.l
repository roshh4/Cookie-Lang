%{
#include "parser.tab.h"
#include <stdlib.h>
%}

%%
[ \t\n]+              ;  
[0-9]+                { yylval.num = atoi(yytext); return NUMBER; }
"+"                   { return PLUS; }
"("                   { return LPAREN; }
")"                   { return RPAREN; }
.                     { /* ignore any other characters */ }
%%

int yywrap(void) { 
    return 1; 
}
