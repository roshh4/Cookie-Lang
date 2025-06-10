#include <iostream>
#include <cstdlib>
#include "ast.h"

extern int yyparse();
extern ASTNode *root;

extern "C" {
    extern int print_int(int value);
}

int evaluate(ASTNode *node) {
    if (node == NULL) {
        return 0;
    }

    switch (node->type) {
        case AST_NUMBER:
            return node->value;
        case AST_ADD:
            return evaluate(node->children[0]) + evaluate(node->children[1]);
        case AST_SUBTRACT:
            return evaluate(node->children[0]) - evaluate(node->children[1]);
        case AST_MULTIPLY:
            return evaluate(node->children[0]) * evaluate(node->children[1]);
        case AST_DIVIDE:
            {
                int divisor = evaluate(node->children[1]);
                if (divisor == 0) {
                    std::cerr << "Error: Division by zero\n";
                    exit(1);
                }
                return evaluate(node->children[0]) / divisor;
            }
        case AST_EQUALS:
            return evaluate(node->children[0]) == evaluate(node->children[1]);
        case AST_NOTEQUALS:
            return evaluate(node->children[0]) != evaluate(node->children[1]);
        case AST_LESSTHAN:
            return evaluate(node->children[0]) < evaluate(node->children[1]);
        case AST_GREATERTHAN:
            return evaluate(node->children[0]) > evaluate(node->children[1]);
        case AST_LESSEQUAL:
            return evaluate(node->children[0]) <= evaluate(node->children[1]);
        case AST_GREATEREQUAL:
            return evaluate(node->children[0]) >= evaluate(node->children[1]);
        case AST_IF:
            if (evaluate(node->children[0])) {
                evaluate(node->children[1]);
            }
            return 0;
        case AST_IF_ELSE:
            if (evaluate(node->children[0])) {
                evaluate(node->children[1]);
            } else {
                evaluate(node->children[2]);
            }
            return 0;
        case AST_WHILE:
            while (evaluate(node->children[0])) {
                evaluate(node->children[1]);
            }
            return 0;
        case AST_PRINT:
            print_int(evaluate(node->children[0]));
            return 0;
        case AST_RETURN:
            return evaluate(node->children[0]);
        case AST_STATEMENTS:
            evaluate(node->children[0]);
            evaluate(node->children[1]);
            return 0;
        case AST_ASSIGN:
            // In a real compiler, this would involve symbol table lookup and assignment
            std::cerr << "Error: Assignment not implemented in evaluation\n";
            exit(1);
            return 0;
        case AST_IDENTIFIER:
            std::cerr << "Error: Identifier evaluation not implemented\n";
            exit(1);
            return 0;
        case AST_COOKIE:
            for (int i = 0; i < 10; i++) {
                print_int(42);
            }
            return 0;
        default:
            std::cerr << "Error: Unknown AST node type\n";
            exit(1);
    }
}

int main() {
    if (yyparse() == 0) {
        evaluate(root);
    } else {
        std::cerr << "Error: Parsing failed\n";
        return 1;
    }

    return 0;
}
