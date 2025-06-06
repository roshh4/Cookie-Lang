
No changes needed in this file.

**Explanation:**

1.  **`ast.h`**: We add `AST_COOKIE` to the enumeration of AST node types.  This is necessary to identify "cookie" nodes in the AST.

2.  **`parser.y`**:
    *   We add `COOKIE` to the list of tokens.
    *   We define a rule for parsing the `cookie()` statement.  This rule creates an `AST_COOKIE` node in the AST.

3.  **`lexer.l`**: We add a rule to the lexer to recognize the `cookie` keyword and return the `COOKIE` token.

4.  **`runtime.c`**: We add a case to the `evaluate` function to handle `AST_COOKIE` nodes.  This case prints "cookie" ten times.

This solution ensures that when the code encounters the statement `cookie();`, the lexer identifies "cookie" as a keyword, the parser creates an appropriate node in the AST, and the runtime executes the logic to print "cookie" 10 times.  The parentheses are mandatory because that's the syntax included in the bison grammar.
