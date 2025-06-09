#ifndef AST_H
#define AST_H

typedef enum {
    NUMBER_NODE,
    IDENTIFIER_NODE,
    BINARY_OP_NODE
} NodeType;

typedef enum {
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE
} OperationType;

typedef struct ASTNode {
    NodeType type;
    int line_number;
    union {
        int number_value;
        char *identifier_name;
        struct {
            OperationType op;
            struct ASTNode *left;
            struct ASTNode *right;
        } binary_op;
    } data;
} ASTNode;

extern int yylineno;

ASTNode *createNumberNode(int value);
ASTNode *createIdentifierNode(char *name);
ASTNode *createBinaryOpNode(OperationType op, ASTNode *left, ASTNode *right);

#endif