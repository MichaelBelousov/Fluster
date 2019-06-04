#include "lambda.h"
#include <llvm/IR/Function.h>
#include "comma_delimited_list.h"
#include "expr.h"
#include "context.h"

namespace fluster { namespace ast {



//// Methods
    
llvm::Value*
Lambda::
generateCode(GenerationContext& ctx) const
{
    std::vector<llvm::Type*> arg_types;
    std::transform(
        args.begin(), args.end(),
        std::back_inserter(arg_types),
        [](const auto& a){ return a->type->llvm_repr; }
    );

    auto func_llvm_type = llvm::FunctionType::get(
        body->result_type->llvm_repr,
        false
    );

    auto llvm_func = llvm::Function::Create(
        func_llvm_type,
        llvm::Function::ExternalLinkage,
        "anonymous",  //TODO: lambda are anonymous, so generate one
        ctx.llvm_module
    );

    {
        unsigned i = 0;
        for (auto& arg : llvm_func->args())
            arg.setName(i++);
    }

    BasicBlock* func_block = llvm::BasicBlock::Create(
        ctx.llvm_context,
        "func_block",
        llvm_func
    );
    ctx.builder.SetInsertPoint(func_block);

    // add arguments to scope of future AST nodes?
    auto func_retval = body->generateCode(ctx);
    ctx.builder.CreateRet(func_retval)

    llvm::verifyFunction(*llvm_func);
    // if errors:
    //llvm_func->eraseFromParent();

    return llvm_func;
}

//// Construction

Lambda::
Lambda( CommaDelimitedList::Ptr in_args
      , Expr::Ptr in_body
      )
    : args(in_args)
    , body(in_body)
{}



} }
