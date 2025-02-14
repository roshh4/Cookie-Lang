#include <map>
#include <vector>
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Verifier.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/GlobalVariable.h"
#include "ast.h"
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace llvm;

// Ensure yyparse is declared with C linkage.
extern "C" int yyparse();

// Global LLVM objects.
LLVMContext Context;
Module *TheModule = new Module("GoofyLang", Context);
IRBuilder<> Builder(Context);

// This map now holds pointers to allocated storage for variables.
std::map<std::string, Value*> NamedValues; 

// Declare the AST root built by the parser.
extern ASTNode* root;

// Forward declaration for AST printing.
extern void printAST(ASTNode* node, int level);

// Utility: Create an alloca instruction in the entry block of a function.
static AllocaInst* CreateEntryBlockAlloca(Function* TheFunction, const std::string &VarName) {
    IRBuilder<> TmpB(&TheFunction->getEntryBlock(), TheFunction->getEntryBlock().begin());
    return TmpB.CreateAlloca(Type::getInt32Ty(Context), nullptr, VarName);
}

// Helper: Get or create the declaration for printf.
Function* getPrintfFunction() {
    Function *printfFunc = TheModule->getFunction("printf");
    if (!printfFunc) {
        std::vector<Type*> printfArgs;
        // Use PointerType::get to get i8* type.
        printfArgs.push_back(PointerType::get(Type::getInt8Ty(Context), 0));
        FunctionType* printfType = FunctionType::get(Type::getInt32Ty(Context), printfArgs, true);
        printfFunc = Function::Create(printfType, Function::ExternalLinkage, "printf", TheModule);
    }
    return printfFunc;
}

// Helper: Get or create a global format string constant "%d\n".
GlobalVariable* getFormatString() {
    GlobalVariable *fmtStrVar = TheModule->getNamedGlobal(".str");
    if (!fmtStrVar) {
        Constant *formatStr = ConstantDataArray::getString(Context, "%d\n", true);
        fmtStrVar = new GlobalVariable(*TheModule, formatStr->getType(), true,
                                       GlobalValue::PrivateLinkage, formatStr, ".str");
    }
    return fmtStrVar;
}

/// generateIR - Recursively generate LLVM IR from the AST.
/// The parameter 'currentFunction' is needed for creating allocas.
Value *generateIR(ASTNode *node, Function* currentFunction) {
    if (!node) return nullptr;
    
    if (strcmp(node->type, "NUMBER") == 0) {
        return ConstantInt::get(Type::getInt32Ty(Context), atoi(node->value));
    }
    if (strcmp(node->type, "IDENTIFIER") == 0) {
        // Load the variable's value from its allocated storage.
        Value* varPtr = NamedValues[node->value];
        if (!varPtr) {
            std::cerr << "Unknown variable: " << node->value << std::endl;
            return ConstantInt::get(Type::getInt32Ty(Context), 0);
        }
        // Pass node->value directly since it's already a C-string.
        return Builder.CreateLoad(Type::getInt32Ty(Context), varPtr, node->value);
    }
    if (strcmp(node->type, "ADD") == 0) {
        Value *L = generateIR(node->left, currentFunction);
        Value *R = generateIR(node->right, currentFunction);
        return Builder.CreateAdd(L, R, "addtmp");
    }
    if (strcmp(node->type, "SUB") == 0) {
        Value *L = generateIR(node->left, currentFunction);
        Value *R = generateIR(node->right, currentFunction);
        return Builder.CreateSub(L, R, "subtmp");
    }
    if (strcmp(node->type, "MUL") == 0) {
        Value *L = generateIR(node->left, currentFunction);
        Value *R = generateIR(node->right, currentFunction);
        return Builder.CreateMul(L, R, "multmp");
    }
    if (strcmp(node->type, "DIV") == 0) {
        Value *L = generateIR(node->left, currentFunction);
        Value *R = generateIR(node->right, currentFunction);
        return Builder.CreateSDiv(L, R, "divtmp");
    }
    if (strcmp(node->type, "ASSIGN") == 0) {
        // Evaluate the right-hand expression.
        std::string varName = node->value;
        Value *exprVal = generateIR(node->left, currentFunction);
        Value *varPtr = NamedValues[varName];
        if (!varPtr) {
            // Create storage for the variable if it doesn't exist.
            varPtr = CreateEntryBlockAlloca(currentFunction, varName);
            NamedValues[varName] = varPtr;
        }
        Builder.CreateStore(exprVal, varPtr);
        return exprVal;
    }
    if (strcmp(node->type, "PRINT") == 0) {
        Value *exprVal = generateIR(node->left, currentFunction);
        // Generate a call to printf to print the integer.
        Function *printfFunc = getPrintfFunction();
        GlobalVariable *fmtStrVar = getFormatString();
        Constant *zero = ConstantInt::get(Type::getInt32Ty(Context), 0);
        std::vector<Constant*> indices = {zero, zero};
        Constant *fmtStrPtr = ConstantExpr::getGetElementPtr(fmtStrVar->getValueType(), fmtStrVar, indices);
        Builder.CreateCall(printfFunc, {fmtStrPtr, exprVal});
        return exprVal;
    }
    if (strcmp(node->type, "LOOP") == 0) {
        // Create a proper loop structure.
        int loopCount = atoi(node->value);
        // Allocate a loop counter.
        AllocaInst *loopVar = CreateEntryBlockAlloca(currentFunction, "i");
        Builder.CreateStore(ConstantInt::get(Type::getInt32Ty(Context), 0), loopVar);
        
        // Create basic blocks for the loop.
        BasicBlock *loopCondBB = BasicBlock::Create(Context, "loopcond", currentFunction);
        BasicBlock *loopBodyBB = BasicBlock::Create(Context, "loopbody", currentFunction);
        BasicBlock *afterLoopBB = BasicBlock::Create(Context, "afterloop", currentFunction);
        
        // Branch to loop condition.
        Builder.CreateBr(loopCondBB);
        
        // Loop condition block.
        Builder.SetInsertPoint(loopCondBB);
        Value *currVal = Builder.CreateLoad(Type::getInt32Ty(Context), loopVar, "i");
        Value *loopLimit = ConstantInt::get(Type::getInt32Ty(Context), loopCount);
        Value *cond = Builder.CreateICmpSLT(currVal, loopLimit, "loopcond");
        Builder.CreateCondBr(cond, loopBodyBB, afterLoopBB);
        
        // Loop body block.
        Builder.SetInsertPoint(loopBodyBB);
        // Generate IR for the loop body.
        generateIR(node->left, currentFunction);
        // Increment the loop counter.
        Value *nextVal = Builder.CreateAdd(currVal, ConstantInt::get(Type::getInt32Ty(Context), 1), "inc");
        Builder.CreateStore(nextVal, loopVar);
        Builder.CreateBr(loopCondBB);
        
        // After loop block.
        Builder.SetInsertPoint(afterLoopBB);
        // The loop returns void here, so we return 0.
        return ConstantInt::get(Type::getInt32Ty(Context), 0);
    }
    if (strcmp(node->type, "STATEMENT_LIST") == 0) {
        // Generate IR for the left subtree for its side effects.
        if (node->left)
            generateIR(node->left, currentFunction);
        // Then generate IR for the right subtree and return its value.
        if (node->right)
            return generateIR(node->right, currentFunction);
        return nullptr;
    }
    return nullptr;
}

int main() {
    // Parse input to build the AST.
    if (yyparse() != 0) {
        // Parsing failed; exit silently (or handle errors as desired)
        return 1;
    }
    
    // Create the main function with return type i32.
    FunctionType *funcType = FunctionType::get(Type::getInt32Ty(Context), false);
    Function *mainFunc = Function::Create(funcType, Function::ExternalLinkage, "main", TheModule);
    BasicBlock *entryBB = BasicBlock::Create(Context, "entry", mainFunc);
    Builder.SetInsertPoint(entryBB);
    
    // Generate IR from the AST.
    Value *retVal = generateIR(root, mainFunc);
    if (!retVal) {
        retVal = ConstantInt::get(Type::getInt32Ty(Context), 0);
    }
    Builder.CreateRet(retVal);
    
    // Verify the module.
    std::string error;
    raw_string_ostream errorStream(error);
    if (verifyModule(*TheModule, &errorStream)) {
        // If verification fails, exit without printing extra messages.
        return 1;
    }
    
    // Print the generated LLVM IR to stdout.
    TheModule->print(outs(), nullptr);
    
    delete TheModule;
    return 0;
}
