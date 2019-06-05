#include <iostream>
#include <llvm/IR/Constants.h>
#include <llvm/Support/raw_ostream.h>
#include "float.h"
#include "context.h"

namespace fluster { namespace ast { namespace lits {


//// Methods

void
Float::
commit(db::ProgramDatabase& db) const
{}


llvm::Value*
Float::
generateCode(GenerationContext& ctx) const
{
    return llvm::ConstantFP::get(ctx.context, llvm::APFloat(value));
}


void
Float::
print(std::ostream& os, unsigned indent_level) const
{
    for (unsigned i = 0; i < indent_level; ++i) llvm::outs() << " ";
    llvm::outs() << "<float value=\"";
    value.print(llvm::outs());
    llvm::outs() << "\"/>" << '\n';
}



} } }  //namespace fluster::ast::lits
