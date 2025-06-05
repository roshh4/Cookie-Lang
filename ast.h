CHANGES:
typedef enum {
  /* existing enums */
  AST_PRINT,
  AST_COOKIE // Add this enum
} ASTNodeType;

typedef struct ASTNode {
  ASTNodeType type;
  union {
    /* existing union members */
    char* stringValue; // used for print
  } value;
  struct ASTNode *left;
  struct ASTNode *right;
} ASTNode;
LOCATION: Add `AST_COOKIE` to the `ASTNodeType` enum.  This indicates a "cookie" node in the Abstract Syntax Tree.  Place it near other function call type definitions like `AST_PRINT`.
