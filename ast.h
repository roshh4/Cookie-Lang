#ifndef AST_H
#define AST_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ASTNode {
    char* type;              // Node type (e.g. "NUMBER", "ASSIGN", "IF", "IF_ELSE", etc.)
    char* value;             // Extra string value (identifier name or literal)
    struct ASTNode* left;    // Left child (for binary operators, condition, etc.)
    struct ASTNode* right;   // Right child (for binary operators, then/else branches, etc.)
} ASTNode;

ASTNode* createASTNode(char* type, char* value, ASTNode* left, ASTNode* right);
void printAST(ASTNode* node, int level);
void freeAST(ASTNode* node);

#ifdef __cplusplus
}
#endif

#endif
