#ifndef FLUSTER_COMPILER_CONTEXT
#define FLUSTER_COMPILER_CONTEXT

#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/Function.h>
#include "db/program_database.h"

namespace fluster {



/*
 * each translation unit is its own namespace, and should have an 'exec'
 * function, which is its entry point. The compiler's argument determines the
 * actual program entry point, main.
 */

struct GenerationContext
{
    GenerationContext();

    void finalize();
    void optimize();
    void emit();

    llvm::LLVMContext context;
    llvm::IRBuilder<> builder;
    std::unique_ptr<llvm::legacy::PassManager> pass_manager;
    std::unique_ptr<llvm::Module> module;
    db::ProgramDatabase db;
    std::unique_ptr<llvm::Function> main;
};



}  //namespace fluster

#endif //FLUSTER_COMPILER_CONTEXT
