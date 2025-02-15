#ifndef AST_H
#define AST_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ASTNode {
    char* type;
    char* value;
    struct ASTNode* left;
    struct ASTNode* right;
} ASTNode;

// Function prototypes
ASTNode* createASTNode(char* type, char* value, ASTNode* left, ASTNode* right);
void printAST(ASTNode* node, int level);
void freeAST(ASTNode* node);

#ifdef __cplusplus
}
#endif

#endif