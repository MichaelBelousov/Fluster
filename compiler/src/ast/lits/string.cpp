#include <llvm/IR/Constants.h>
#include "string.h"

namespace fluster { namespace ast { namespace lits {



//// Methods

llvm::Value*
Integer::
generateCode(GenerationContext& ctx) const
{
    return llvm::ConstantArray::get(ctx, value);
}

//// Construction

String::
String(const atoms::String& in_value)
    : value(in_value)
{}

void
String::
print(std::ostream& os, unsigned indent_level) const
{
    for (unsigned i = 0; i < indent_level; ++i) os << " ";
    os << "<string value=\"" << value << "\">" << std::endl;
}



} } }
