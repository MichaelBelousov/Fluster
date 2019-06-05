#ifndef FLUSTER_COMPILER_CONTEXT
#define FLUSTER_COMPILER_CONTEXT

#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Value.h>
#include "db/program_database.h"

namespace fluster {


//namespace db { struct ProgramDatabase; }

struct GenerationContext
{
    GenerationContext();

    llvm::LLVMContext context;
    llvm::IRBuilder<> builder;
    std::unique_ptr<llvm::Module> module;
    db::ProgramDatabase db;
};



}  //namespace fluster

#endif //FLUSTER_COMPILER_CONTEXT
