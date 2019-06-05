#include "integer.h"
#include <iostream>
#include <llvm/IR/Constants.h>
#include <llvm/Support/raw_ostream.h>
#include "context.h"

namespace fluster { namespace ast { namespace lits {


    
//// Methods


void
Integer::
commit(db::ProgramDatabase& db) const
{}


llvm::Value*
Integer::
generateCode(GenerationContext& ctx) const
{
    return llvm::ConstantInt::get(ctx.context, value);
}


void
Integer::
print(std::ostream& os, unsigned indent_level) const
{
    // TODO: use llvm's ostream for colors and speed across the board,
    // without std::iostream
    for (unsigned i = 0; i < indent_level; ++i) llvm::outs() << " ";
    llvm::outs() << "<integer value=\"";
    value.print(llvm::outs(), /*signed=*/true);
    llvm::outs() << "\"/>" << '\n';
}



} } }
