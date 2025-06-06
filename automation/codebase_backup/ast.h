COMPLETE CODE:
#ifndef AST_H
#define AST_H

#include <stdio.h>

typedef enum {
    NODE_PROGRAM,
    NODE_STATEMENT_LIST,
    NODE_ASSIGNMENT,
    NODE_IDENTIFIER,
    NODE_INTEGER,
    NODE_BINARY_OP,
    NODE_PRINT,
    NODE_IF,
    NODE_WHILE,
    NODE_BLOCK,
    NODE_FUNCTION_DEF,
    NODE_FUNCTION_CALL,
    NODE_RETURN,
    NODE_STRING,
    NODE_COOKIE // New AST Node
} NodeType;

typedef struct ASTNode {
    NodeType type;
    int lineno;
    union {
        struct {
            struct ASTNode* statements;
        } program;
        struct {
            struct ASTNode* statement;
            struct ASTNode* next;
        } statement_list;
        struct {
            char* identifier;
            struct ASTNode* expression;
        } assignment;
        char* identifier;
        int integer;
        struct {
            char* op;
            struct ASTNode* left;
            struct ASTNode* right;
        } binary_op;
        struct ASTNode* expression;
        struct {
            struct ASTNode* condition;
            struct ASTNode* then_block;
            struct ASTNode* else_block;
        } if_statement;
        struct {
            struct ASTNode* condition;
            struct ASTNode* body;
        } while_loop;
        struct {
            struct ASTNode* statements;
        } block;
        struct {
            char* identifier;
            struct ASTNode* parameters;
            struct ASTNode* body;
        } function_def;
        struct {
            char* identifier;
            struct ASTNode* arguments;
        } function_call;
        struct ASTNode* expression;
        char* string;
    } data;
} ASTNode;

ASTNode* createASTNode(NodeType type, int lineno);
ASTNode* createProgramNode(ASTNode* statements, int lineno);
ASTNode* createStatementListNode(ASTNode* statement, ASTNode* next, int lineno);
ASTNode* createAssignmentNode(char* identifier, ASTNode* expression, int lineno);
ASTNode* createIdentifierNode(char* identifier, int lineno);
ASTNode* createIntegerNode(int value, int lineno);
ASTNode* createBinaryOpNode(char* op, ASTNode* left, ASTNode* right, int lineno);
ASTNode* createPrintNode(ASTNode* expression, int lineno);
ASTNode* createIfNode(ASTNode* condition, ASTNode* then_block, ASTNode* else_block, int lineno);
ASTNode* createWhileNode(ASTNode* condition, ASTNode* body, int lineno);
ASTNode* createBlockNode(ASTNode* statements, int lineno);
ASTNode* createFunctionDefNode(char* identifier, ASTNode* parameters, ASTNode* body, int lineno);
ASTNode* createFunctionCallNode(char* identifier, ASTNode* arguments, int lineno);
ASTNode* createReturnNode(ASTNode* expression, int lineno);
ASTNode* createStringNode(char* string, int lineno);
ASTNode* createCookieNode(int lineno); // New AST Node Creation

void freeAST(ASTNode* node);
void printAST(ASTNode* node, int indent);

#endif
