#include <iostream>
#include <llvm/IR/Constants.h>
#include "integer.h"

namespace fluster { namespace ast { namespace lits {


    
//// Methods


llvm::Value*
Integer::
generateCode(GenerationContext& ctx) const
{
    return llvm::ConstantInt::get(ctx.context, value);
}


//// Construction


Integer::
Integer(const llvm::APInt& in_value)
    : value(in_value)
{}


void
Integer::
print(std::ostream& os, unsigned indent_level) const
{
    for (unsigned i = 0; i < indent_level; ++i) os << " ";
    os << "<integer value=\"" << value << "\">" << std::endl;
}



} } }
