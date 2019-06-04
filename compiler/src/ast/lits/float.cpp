#include <iostream>
#include <llvm/IR/Constants.h>
#include "float.h"
#include "context.h"

namespace fluster { namespace ast { namespace lits {


//// Methods

llvm::Value*
Float::
generateCode(GenerationContext& ctx) const
{
    return llvm::ConstantFP::get(ctx.context, APFloat(value));
}


void
Float::
print(std::ostream& os, unsigned indent_level) const
{
    for (unsigned i = 0; i < indent_level; ++i) os << " ";
    os << "<float value=\"" << value << "\">" << std::endl;
}



} } }  //namespace fluster::ast::lits
