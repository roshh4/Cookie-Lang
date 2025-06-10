#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

ASTNode* createASTNode(char* type, char* value, ASTNode* left, ASTNode* right) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = strdup(type);
    node->value = value ? strdup(value) : NULL;
    node->left = left;
    node->right = right;
    return node;
}

void printAST(ASTNode* node, int level) {
    if (node == NULL) return;
    
    for (int i = 0; i < level; i++) printf("  ");
    printf("%s", node->type);
    if (node->value) printf(": %s", node->value);
    printf("\n");
    
    printAST(node->left, level + 1);
    printAST(node->right, level + 1);
}

void freeAST(ASTNode* node) {
    if (node == NULL) return;
    
    freeAST(node->left);
    freeAST(node->right);
    free(node->type);
    if (node->value) free(node->value);
    free(node);
} 