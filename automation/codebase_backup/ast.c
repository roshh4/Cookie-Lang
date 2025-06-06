#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

ASTNode *createNumberNode(int value) {
    ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
    if (!node) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    node->type = NUMBER_NODE;
    node->line_number = yylineno;
    node->data.number_value = value;
    return node;
}

ASTNode *createIdentifierNode(char *name) {
    ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
    if (!node) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    node->type = IDENTIFIER_NODE;
    node->line_number = yylineno;
    node->data.identifier_name = strdup(name);
    if (!node->data.identifier_name) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    return node;
}

ASTNode *createBinaryOpNode(OperationType op, ASTNode *left, ASTNode *right) {
    ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
    if (!node) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    node->type = BINARY_OP_NODE;
    node->line_number = yylineno;
    node->data.binary_op.op = op;
    node->data.binary_op.left = left;
    node->data.binary_op.right = right;
    return node;
}
