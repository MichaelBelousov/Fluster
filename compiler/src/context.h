#ifndef FLUSTER_COMPILER_CONTEXT
#define FLUSTER_COMPILER_CONTEXT

#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Value.h"

namespace fluster {

// MEH: too much work to wrap backends
struct LLVM : public Backend
{
    llvm::LLVMContext llvm_context;
    llvm::IRBuilder<> llvm_build(llvm_context);
    std::shared_ptr<llvm::Module> llvm_module;
    std::map<std::string, Value*> symbol_table;

    Context getContext() override;
};

}  //namespace fluster

#endif //FLUSTER_COMPILER_CONTEXT
