CHANGES:
"print"     { yylval.sval = strdup(yytext); return PRINT; }
"cookie"    { yylval.sval = strdup(yytext); return COOKIE; } // add COOKIE keyword
[a-zA-Z_][a-zA-Z0-9_]* { yylval.sval = strdup(yytext); return IDENTIFIER; }
LOCATION: Add a rule to recognize the "cookie" keyword. This maps the string "cookie" to the `COOKIE` token defined in the parser.  Make sure this is placed before the identifier rule, or the lexer will treat "cookie" as an identifier.
