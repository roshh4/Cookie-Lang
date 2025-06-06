CHANGES:
#include <stdio.h>
#include "ast.h"

/* existing evaluate function */

void evaluate(ASTNode *node) {
  if (node == NULL) {
    return;
  }

  switch (node->type) {
    /* existing cases */
    case AST_PRINT: {
      evaluate(node->value.node);
      break;
    }
    case AST_COOKIE: { // add COOKIE case
      for (int i = 0; i < 10; i++) {
        printf("cookie\n");
      }
      break;
    }
    default:
      printf("Unknown node type\n");
  }
}

LOCATION: Add a `case AST_COOKIE:` to the `switch` statement in the `evaluate` function.  This is where the actual "cookie" printing logic is implemented.  The loop prints "cookie" ten times, followed by a newline character.
