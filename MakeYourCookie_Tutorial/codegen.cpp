#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Verifier.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/IR/Type.h>
#include <map>
#include <string>
#include "ast.h"

using namespace llvm;

static LLVMContext TheContext;
static IRBuilder<> Builder(TheContext);
static std::unique_ptr<Module> TheModule;
static std::map<std::string, Value*> NamedValues;

Value* codegen(ASTNode* node) {
    if (!node) return nullptr;

    if (strcmp(node->type, "NUMBER") == 0) {
        return ConstantInt::get(TheContext, APInt(32, std::stoi(node->value), true));
    }

    if (strcmp(node->type, "IDENTIFIER") == 0) {
        Value* V = NamedValues[node->value];
        if (!V) {
            fprintf(stderr, "Unknown variable name: %s\n", node->value);
            return nullptr;
        }
        return V;
    }

    if (strcmp(node->type, "PLUS") == 0) {
        Value* L = codegen(node->left);
        Value* R = codegen(node->right);
        if (!L || !R) return nullptr;
        return Builder.CreateAdd(L, R, "addtmp");
    }

    if (strcmp(node->type, "ASSIGN") == 0) {
        Value* Val = codegen(node->left);
        if (!Val) return nullptr;
        NamedValues[node->value] = Val;
        return Val;
    }

    if (strcmp(node->type, "PRINT") == 0) {
        Value* Val = codegen(node->left);
        if (!Val) return nullptr;
        
        // Create printf function
        std::vector<Type*> printfArgs;
        printfArgs.push_back(PointerType::get(Builder.getInt8Ty(), 0));
        FunctionType* printfType = FunctionType::get(Builder.getInt32Ty(), printfArgs, true);
        Function* printfFunc = Function::Create(printfType, Function::ExternalLinkage, "printf", TheModule.get());
        
        // Create format string
        Value* formatStr = Builder.CreateGlobalString("%d\n");
        
        // Call printf
        std::vector<Value*> args;
        args.push_back(formatStr);
        args.push_back(Val);
        return Builder.CreateCall(printfFunc, args, "printtmp");
    }

    if (strcmp(node->type, "STATEMENT_LIST") == 0) {
        Value* L = codegen(node->left);
        Value* R = codegen(node->right);
        if (!L || !R) return nullptr;
        return R;
    }

    return nullptr;
}

extern "C" {
    void generateCode(ASTNode* root) {
        TheModule = std::make_unique<Module>("my_module", TheContext);
        
        // Create main function
        FunctionType* mainType = FunctionType::get(Builder.getInt32Ty(), false);
        Function* mainFunc = Function::Create(mainType, Function::ExternalLinkage, "main", TheModule.get());
        
        // Create entry block
        BasicBlock* entry = BasicBlock::Create(TheContext, "entry", mainFunc);
        Builder.SetInsertPoint(entry);
        
        // Generate code for the AST
        Value* retVal = codegen(root);
        
        // Return 0
        Builder.CreateRet(ConstantInt::get(TheContext, APInt(32, 0)));
        
        // Verify the module
        verifyFunction(*mainFunc);
        
        // Print the IR
        TheModule->print(outs(), nullptr);
    }
}

extern "C" int yyparse();
extern ASTNode* root;

int main() {
    if (yyparse() != 0) {
        return 1;
    }
    generateCode(root);
    return 0;
} 