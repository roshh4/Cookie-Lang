COMPLETE CODE:
#include "ast.h"
#include <stdlib.h>
#include <string.h>

ASTNode* createASTNode(NodeType type, int lineno) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    if (!node) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    node->type = type;
    node->lineno = lineno;
    return node;
}

ASTNode* createProgramNode(ASTNode* statements, int lineno) {
    ASTNode* node = createASTNode(NODE_PROGRAM, lineno);
    node->data.program.statements = statements;
    return node;
}

ASTNode* createStatementListNode(ASTNode* statement, ASTNode* next, int lineno) {
    ASTNode* node = createASTNode(NODE_STATEMENT_LIST, lineno);
    node->data.statement_list.statement = statement;
    node->data.statement_list.next = next;
    return node;
}

ASTNode* createAssignmentNode(char* identifier, ASTNode* expression, int lineno) {
    ASTNode* node = createASTNode(NODE_ASSIGNMENT, lineno);
    node->data.assignment.identifier = strdup(identifier);
    node->data.assignment.expression = expression;
    return node;
}

ASTNode* createIdentifierNode(char* identifier, int lineno) {
    ASTNode* node = createASTNode(NODE_IDENTIFIER, lineno);
    node->data.identifier = strdup(identifier);
    return node;
}

ASTNode* createIntegerNode(int value, int lineno) {
    ASTNode* node = createASTNode(NODE_INTEGER, lineno);
    node->data.integer = value;
    return node;
}

ASTNode* createBinaryOpNode(char* op, ASTNode* left, ASTNode* right, int lineno) {
    ASTNode* node = createASTNode(NODE_BINARY_OP, lineno);
    node->data.binary_op.op = strdup(op);
    node->data.binary_op.left = left;
    node->data.binary_op.right = right;
    return node;
}

ASTNode* createPrintNode(ASTNode* expression, int lineno) {
    ASTNode* node = createASTNode(NODE_PRINT, lineno);
    node->data.expression = expression;
    return node;
}

ASTNode* createIfNode(ASTNode* condition, ASTNode* then_block, ASTNode* else_block, int lineno) {
    ASTNode* node = createASTNode(NODE_IF, lineno);
    node->data.if_statement.condition = condition;
    node->data.if_statement.then_block = then_block;
    node->data.if_statement.else_block = else_block;
    return node;
}

ASTNode* createWhileNode(ASTNode* condition, ASTNode* body, int lineno) {
    ASTNode* node = createASTNode(NODE_WHILE, lineno);
    node->data.while_loop.condition = condition;
    node->data.while_loop.body = body;
    return node;
}

ASTNode* createBlockNode(ASTNode* statements, int lineno) {
    ASTNode* node = createASTNode(NODE_BLOCK, lineno);
    node->data.block.statements = statements;
    return node;
}

ASTNode* createFunctionDefNode(char* identifier, ASTNode* parameters, ASTNode* body, int lineno) {
    ASTNode* node = createASTNode(NODE_FUNCTION_DEF, lineno);
    node->data.function_def.identifier = strdup(identifier);
    node->data.function_def.parameters = parameters;
    node->data.function_def.body = body;
    return node;
}

ASTNode* createFunctionCallNode(char* identifier, ASTNode* arguments, int lineno) {
    ASTNode* node = createASTNode(NODE_FUNCTION_CALL, lineno);
    node->data.function_call.identifier = strdup(identifier);
    node->data.function_call.arguments = arguments;
    return node;
}

ASTNode* createReturnNode(ASTNode* expression, int lineno) {
    ASTNode* node = createASTNode(NODE_RETURN, lineno);
    node->data.expression = expression;
    return node;
}

ASTNode* createStringNode(char* string, int lineno) {
    ASTNode* node = createASTNode(NODE_STRING, lineno);
    node->data.string = strdup(string);
    return node;
}

ASTNode* createCookieNode(int lineno) { // New AST Node Creation
    ASTNode* node = createASTNode(NODE_COOKIE, lineno);
    return node;
}

void freeAST(ASTNode* node) {
    if (!node) return;

    switch (node->type) {
        case NODE_PROGRAM:
            freeAST(node->data.program.statements);
            break;
        case NODE_STATEMENT_LIST:
            freeAST(node->data.statement_list.statement);
            freeAST(node->data.statement_list.next);
            break;
        case NODE_ASSIGNMENT:
            free(node->data.assignment.identifier);
            freeAST(node->data.assignment.expression);
            break;
        case NODE_IDENTIFIER:
            free(node->data.identifier);
            break;
        case NODE_BINARY_OP:
            free(node->data.binary_op.op);
            freeAST(node->data.binary_op.left);
            freeAST(node->data.binary_op.right);
            break;
        case NODE_PRINT:
            freeAST(node->data.expression);
            break;
        case NODE_IF:
            freeAST(node->data.if_statement.condition);
            freeAST(node->data.if_statement.then_block);
            freeAST(node->data.if_statement.else_block);
            break;
        case NODE_WHILE:
            freeAST(node->data.while_loop.condition);
            freeAST(node->data.while_loop.body);
            break;
        case NODE_BLOCK:
            freeAST(node->data.block.statements);
            break;
        case NODE_FUNCTION_DEF:
            free(node->data.function_def.identifier);
            freeAST(node->data.function_def.parameters);
            freeAST(node->data.function_def.body);
            break;
        case NODE_FUNCTION_CALL:
            free(node->data.function_call.identifier);
            freeAST(node->data.function_call.arguments);
            break;
        case NODE_RETURN:
            freeAST(node->data.expression);
            break;
        case NODE_STRING:
            free(node->data.string);
            break;
        case NODE_COOKIE:
            // No data to free for COOKIE node
            break;
        default:
            fprintf(stderr, "Unknown node type in freeAST\n");
    }
    free(node);
}

void printAST(ASTNode* node, int indent) {
    if (!node) return;

    for (int i = 0; i < indent; i++) printf("    ");

    switch (node->type) {
        case NODE_PROGRAM:
            printf("Program:\n");
            printAST(node->data.program.statements, indent + 1);
            break;
        case NODE_STATEMENT_LIST:
            printf("Statement List:\n");
            printAST(node->data.statement_list.statement, indent + 1);
            printAST(node->data.statement_list.next, indent);
            break;
        case NODE_ASSIGNMENT:
            printf("Assignment: %s =\n", node->data.assignment.identifier);
            printAST(node->data.assignment.expression, indent + 1);
            break;
        case NODE_IDENTIFIER:
            printf("Identifier: %s\n", node->data.identifier);
            break;
        case NODE_INTEGER:
            printf("Integer: %d\n", node->data.integer);
            break;
        case NODE_BINARY_OP:
            printf("Binary Op: %s\n", node->data.binary_op.op);
            printAST(node->data.binary_op.left, indent + 1);
            printAST(node->data.binary_op.right, indent + 1);
            break;
        case NODE_PRINT:
            printf("Print:\n");
            printAST(node->data.expression, indent + 1);
            break;
        case NODE_IF:
            printf("If:\n");
            printf("Condition:\n");
            printAST(node->data.if_statement.condition, indent + 1);
            printf("Then:\n");
            printAST(node->data.if_statement.then_block, indent + 1);
            if (node->data.if_statement.else_block) {
                printf("Else:\n");
                printAST(node->data.if_statement.else_block, indent + 1);
            }
            break;
        case NODE_WHILE:
            printf("While:\n");
            printf("Condition:\n");
            printAST(node->data.while_loop.condition, indent + 1);
            printf("Body:\n");
            printAST(node->data.while_loop.body, indent + 1);
            break;
        case NODE_BLOCK:
            printf("Block:\n");
            printAST(node->data.block.statements, indent + 1);
            break;
        case NODE_FUNCTION_DEF:
            printf("Function Definition: %s\n", node->data.function_def.identifier);
            printf("Parameters:\n");
            printAST(node->data.function_def.parameters, indent + 1);
            printf("Body:\n");
            printAST(node->data.function_def.body, indent + 1);
            break;
        case NODE_FUNCTION_CALL:
            printf("Function Call: %s\n", node->data.function_call.identifier);
            printf("Arguments:\n");
            printAST(node->data.function_call.arguments, indent + 1);
            break;
        case NODE_RETURN:
            printf("Return:\n");
            printAST(node->data.expression, indent + 1);
            break;
        case NODE_STRING:
            printf("String: %s\n", node->data.string);
            break;
        case NODE_COOKIE:
            printf("Cookie\n");
            break;
        default:
            printf("Unknown Node Type\n");
    }
}
