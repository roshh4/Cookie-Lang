#include "ast.h"

#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Verifier.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/ExecutionEngine/MCJIT.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/Support/TargetSelect.h>
#include <iostream>
#include <memory>
#include <vector>

using namespace llvm;

// Global LLVM objects
static LLVMContext TheContext;
static std::unique_ptr<Module> TheModule = std::make_unique<Module>("simple_module", TheContext);
static IRBuilder<> Builder(TheContext);

void generateLLVM() {
    // Create a main function: int main(void)
    FunctionType *FT = FunctionType::get(Type::getInt32Ty(TheContext), false);
    Function *MainF = Function::Create(FT, Function::ExternalLinkage, "main", TheModule.get());
    
    // Create an entry basic block and set the insertion point.
    BasicBlock *BB = BasicBlock::Create(TheContext, "entry", MainF);
    Builder.SetInsertPoint(BB);
    
    // For simplicity, just return constant 7.
    Builder.CreateRet(ConstantInt::get(Type::getInt32Ty(TheContext), 7));
    
    // Verify the function.
    verifyFunction(*MainF);
    
    // Print the generated LLVM IR.
    std::cout << "\nGenerated LLVM IR:\n";
    TheModule->print(outs(), nullptr);
    
    // Initialize LLVM's native target and JIT.
    InitializeNativeTarget();
    InitializeNativeTargetAsmPrinter();
    InitializeNativeTargetAsmParser();
    
    std::string errStr;
    ExecutionEngine *EE = EngineBuilder(std::move(TheModule))
                              .setErrorStr(&errStr)
                              .setEngineKind(EngineKind::JIT)
                              .create();
    if (!EE) {
        std::cerr << "Failed to create ExecutionEngine: " << errStr << "\n";
        return;
    }
    EE->finalizeObject();
    
    // Execute the "main" function.
    std::vector<GenericValue> noargs;
    GenericValue gv = EE->runFunction(MainF, noargs);
    // Convert APInt to a 64-bit signed integer:
    std::cout << "\nJIT-compiled 'main' returned: " << gv.IntVal.getSExtValue() << "\n";
}
