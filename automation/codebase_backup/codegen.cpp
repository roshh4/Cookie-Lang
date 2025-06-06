COMPLETE CODE:
#include <iostream>
#include <fstream>
#include "ast.h"

static int labelCount = 0;

std::string generateLabel() {
    return "L" + std::to_string(labelCount++);
}

void generateCode(ASTNode* node, std::ofstream& outputFile) {
    if (!node) return;

    switch (node->type) {
        case NODE_PROGRAM:
            generateCode(node->data.program.statements, outputFile);
            break;
        case NODE_STATEMENT_LIST:
            generateCode(node->data.statement_list.statement, outputFile);
            generateCode(node->data.statement_list.next, outputFile);
            break;
        case NODE_ASSIGNMENT:
            outputFile << "push " << node->data.assignment.identifier << std::endl;
            generateCode(node->data.assignment.expression, outputFile);
            outputFile << "pop " << node->data.assignment.identifier << std::endl;
            break;
        case NODE_IDENTIFIER:
            outputFile << "push " << node->data.identifier << std::endl;
            break;
        case NODE_INTEGER:
            outputFile << "push " << node->data.integer << std::endl;
            break;
        case NODE_STRING:
            outputFile << "push \"" << node->data.string << "\"" << std::endl;
            break;
        case NODE_BINARY_OP: {
            generateCode(node->data.binary_op.left, outputFile);
            generateCode(node->data.binary_op.right, outputFile);
            outputFile << "pop rbx" << std::endl;
            outputFile << "pop rax" << std::endl;
            if (node->data.binary_op.op == "+") {
                outputFile << "add rax, rbx" << std::endl;
            } else if (node->data.binary_op.op == "-") {
                outputFile << "sub rax, rbx" << std::endl;
            } else if (node->data.binary_op.op == "*") {
                outputFile << "mul rbx" << std::endl;
            } else if (node->data.binary_op.op == "/") {
                outputFile << "div rbx" << std::endl;
            } else if (node->data.binary_op.op == "==") {
                outputFile << "cmp rax, rbx" << std::endl;
                outputFile << "je " << generateLabel() << std::endl;
            } else if (node->data.binary_op.op == "!=") {
                outputFile << "cmp rax, rbx" << std::endl;
                outputFile << "jne " << generateLabel() << std::endl;
            } else if (node->data.binary_op.op == "<") {
                outputFile << "cmp rax, rbx" << std::endl;
                outputFile << "jl " << generateLabel() << std::endl;
            } else if (node->data.binary_op.op == ">") {
                outputFile << "cmp rax, rbx" << std::endl;
                outputFile << "jg " << generateLabel() << std::endl;
            } else if (node->data.binary_op.op == "<=") {
                outputFile << "cmp rax, rbx" << std::endl;
                outputFile << "jle " << generateLabel() << std::endl;
            } else if (node->data.binary_op.op == ">=") {
                outputFile << "cmp rax, rbx" << std::endl;
                outputFile << "jge " << generateLabel() << std::endl;
            }
            outputFile << "push rax" << std::endl;
            break;
        }
        case NODE_PRINT:
            generateCode(node->data.expression, outputFile);
            outputFile << "call print" << std::endl;
            break;
        case NODE_IF: {
            std::string elseLabel = generateLabel();
            std::string endIfLabel = generateLabel();
            generateCode(node->data.if_statement.condition, outputFile);
            outputFile << "pop rax" << std::endl;
            outputFile << "test rax, rax" << std::endl;
            if (node->data.if_statement.else_block) {
                outputFile << "jz " << elseLabel << std::endl;
                generateCode(node->data.if_statement.then_block, outputFile);
                outputFile << "jmp " << endIfLabel << std::endl;
                outputFile << elseLabel << ":" << std::endl;
                generateCode(node->data.if_statement.else_block, outputFile);
            } else {
                outputFile << "jz " << endIfLabel << std::endl;
                generateCode(node->data.if_statement.then_block, outputFile);
            }
            outputFile << endIfLabel << ":" << std::endl;
            break;
        }
        case NODE_WHILE: {
            std::string loopStart = generateLabel();
            std::string loopEnd = generateLabel();
            outputFile << loopStart << ":" << std::endl;
            generateCode(node->data.while_loop.condition, outputFile);
            outputFile << "pop rax" << std::endl;
            outputFile << "test rax, rax" << std::endl;
            outputFile << "jz " << loopEnd << std::endl;
            generateCode(node->data.while_loop.body, outputFile);
            outputFile << "jmp " << loopStart << std::endl;
            outputFile << loopEnd << ":" << std::endl;
            break;
        }
        case NODE_BLOCK:
            generateCode(node->data.block.statements, outputFile);
            break;
        case NODE_FUNCTION_DEF:
            outputFile << node->data.function_def.identifier << ":" << std::endl;
            generateCode(node->data.function_def.body, outputFile);
            outputFile << "ret" << std::endl;
            break;
        case NODE_FUNCTION_CALL:
            outputFile << "call " << node->data.function_call.identifier << std::endl;
            break;
        case NODE_RETURN:
            generateCode(node->data.expression, outputFile);
            outputFile << "ret" << std::endl;
            break;
        case NODE_COOKIE:
            outputFile << "call cookie_function" << std::endl;
            break;
        default:
            std::cerr << "Unknown node type for code generation" << std::endl;
    }
}
