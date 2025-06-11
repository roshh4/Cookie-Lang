%{
#include "parser.tab.h"
#include <stdlib.h>
#include <string.h>
#include "ast.h"
%}

%option noyywrap

%%
"display"                                  { return PRINT; }
"plus"                                   { return PLUS; }
[0-9]+                                   { yylval.str = strdup(yytext); return NUMBER; }
[a-zA-Z_][a-zA-Z0-9_]*                   { yylval.str = strdup(yytext); return IDENTIFIER; }
"="                                      { return ASSIGN; }
";"                                      { return SEMICOLON; }
[ \t]                                    ; /* ignore spaces and tabs */
\n                                       ; /* ignore newlines */
.                                        { /* ignore any other character */ }
%% 