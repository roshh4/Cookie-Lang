#ifndef AST_H
#define AST_H

#include <memory>
#include <vector>
#include <string>
#include <llvm/IR/Value.h>

class ASTNode {
public:
    virtual ~ASTNode() = default;
    virtual llvm::Value *codegen() = 0;
};

class NumberExprAST : public ASTNode {
    double Val;
public:
    NumberExprAST(double Val) : Val(Val) {}
    llvm::Value *codegen() override;
};

class VariableExprAST : public ASTNode {
    std::string Name;
public:
    VariableExprAST(const std::string &Name) : Name(Name) {}
    llvm::Value *codegen() override;
};

class BinaryExprAST : public ASTNode {
    char Op;
    std::unique_ptr<ASTNode> LHS, RHS;
public:
    BinaryExprAST(char Op, std::unique_ptr<ASTNode> LHS, std::unique_ptr<ASTNode> RHS)
        : Op(Op), LHS(std::move(LHS)), RHS(std::move(RHS)) {}
    llvm::Value *codegen() override;
};

class PrintExprAST : public ASTNode {
    std::unique_ptr<ASTNode> Expr;
public:
    PrintExprAST(std::unique_ptr<ASTNode> Expr) : Expr(std::move(Expr)) {}
    llvm::Value *codegen() override;
};

class LoopExprAST : public ASTNode {
    std::unique_ptr<ASTNode> Condition;
    std::vector<std::unique_ptr<ASTNode>> Body;
public:
    LoopExprAST(std::unique_ptr<ASTNode> Condition, std::vector<std::unique_ptr<ASTNode>> Body)
        : Condition(std::move(Condition)), Body(std::move(Body)) {}
    llvm::Value *codegen() override;
};

#endif // AST_H
