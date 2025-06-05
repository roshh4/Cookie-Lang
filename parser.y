CHANGES:
%union {
  int ival;
  double dval;
  char *sval;
  ASTNode *node;
};

/* existing tokens */

%token <sval> IDENTIFIER STRING
%token PRINT
%token COOKIE // add COOKIE token
%type <node> program statement expression term

%%

program:
    statement
    {
        $$ = $1;
    }
    | program statement
    {
        $$ = ast_create(AST_SEQUENCE, $1, $2);
    }
    ;

statement:
    PRINT expression ';'
    {
        $$ = ast_create(AST_PRINT, $2, NULL);
    }
    | COOKIE '(' ')' ';' // add COOKIE rule
    {
        $$ = ast_create(AST_COOKIE, NULL, NULL);
    }
    | IDENTIFIER '=' expression ';'
    {
        $$ = ast_create(AST_ASSIGN, ast_create_identifier($1), $2);
        free($1);
    }
    | /* empty */
    {
        $$ = NULL;
    }
    ;

/* ... other rules ... */
LOCATION:

1.  Add `COOKIE` to the list of tokens:  `%token COOKIE`
2.  Add a production rule for `COOKIE` calls: `COOKIE '(' ')' ';' { $$ = ast_create(AST_COOKIE, NULL, NULL); }`  This rule parses the `cookie()` statement and creates an `AST_COOKIE` node in the AST.  It expects parentheses even though it takes no arguments. This creates the required node when "cookie();" is encountered.
