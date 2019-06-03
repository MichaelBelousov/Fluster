#include "root.h"

namespace fluster { namespace ast { namespace ops {


//// Class Constants

const std::string Root::tag = "root";
const std::string Root::symbol = "^/";

//// Methods

llvm::Value*
Root::
generateCode(GenerationContext& ctx) const
{
    return _generateCode<Root::tag>(ctx);
}

void
Root::
print(std::ostream& os, unsigned indent_level) const
{
    _print<Root::symbol>(os, indent_level);
}

//// Construction

Root::
Root(Expr::Ptr in_lhs, Expr::Ptr in_rhs)
    : BinaryOperator(in_lhs, in_rhs)
{}



} } }
