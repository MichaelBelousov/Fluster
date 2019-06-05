#include "context.h"
#include <llvm/Transforms/InstCombine/InstCombine.h>
#include <llvm/Transforms/Scalar.h>
#include <llvm/Transforms/Scalar/GVN.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Support/TargetRegistry.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/Target/TargetOptions.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Type.h>

namespace fluster {



void
GenerationContext::
finalize()
{
    module = std::make_unique<llvm::Module>("interactive", context);
    //pass_manager = std::make_unique<llvm::legacy::FunctionPassManager>(module.get());
    pass_manager = std::make_unique<llvm::legacy::PassManager>();
}

void
GenerationContext::
optimize()
{
    /*
    pass_manager->add(llvm::createInstructionCombiningPass());
    pass_manager->add(llvm::createReassociatePass());
    pass_manager->add(llvm::createGVNPass());
    pass_manager->add(llvm::createCFGSimplificationPass());
    pass_manager->doInitialization();
    */
}

void
GenerationContext::
emit()
{
    auto target_triple = llvm::sys::getDefaultTargetTriple();

    llvm::InitializeAllTargetInfos();
    llvm::InitializeAllTargets();
    llvm::InitializeAllTargetMCs();
    llvm::InitializeAllAsmParsers();
    llvm::InitializeAllAsmPrinters();

    std::string error;
    auto target = llvm::TargetRegistry::lookupTarget(target_triple, error);
    if (!target)
        llvm::errs() << "Errors:" << error;

    llvm::TargetOptions target_opts;
    auto cpu = "generic";
    auto features = "";

    auto reloc_model = llvm::Optional<llvm::Reloc::Model>();
    auto target_machine = target->createTargetMachine(
        target_triple, cpu, features, target_opts, reloc_model
    );

    module->setDataLayout(target_machine->createDataLayout());
    module->setTargetTriple(target_triple);

    auto filename = "output.o";
    std::error_code errc;
    llvm::raw_fd_ostream dest(filename, errc, llvm::sys::fs::F_None);
    if (errc)
    {
        llvm::errs() << "could not open file: " << errc.message() << '\n';
        throw "failed compilation";
    }

    auto file_type = llvm::TargetMachine::CGFT_ObjectFile;

    llvm::legacy::PassManager pass_mgr;
    if (target_machine->addPassesToEmitFile(pass_mgr, dest, file_type))
    {
        llvm::errs() << "target_machine can't emit a file of this type" << '\n';
        throw "failed compilation";
    }

    pass_manager->run(*module);
}


GenerationContext::
GenerationContext()
    : context()
    , builder(context)
    , pass_manager()
    , module(std::make_unique<llvm::Module>("interactive", context))
    , db()
    , main(
        llvm::Function::Create(
            llvm::FunctionType::get(
                llvm::Type::getInt64Ty(context),
                std::vector<llvm::Type*>({llvm::Type::getInt64Ty(context)}),
                false
            ),
            llvm::Function::ExternalLinkage,
            "main",
            module.get()
        )
    )
{}



}  //namespace fluster
