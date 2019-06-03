#include "int_divide.h"

namespace fluster { namespace ast { namespace ops {



//// Class Constants

const std::string IntDivide::tag = "int_divide";
const std::string IntDivide::symbol = "//";

//// Methods

llvm::Value*
IntDivide::
generateCode(GenerationContext& ctx) const
{
    return _generateCode<IntDivide::tag>(ctx);
}

void
IntDivide::
print(std::ostream& os, unsigned indent_level) const
{
    _print<IntDivide::symbol>(os, indent_level);
}

//// Construction

IntDivide::
IntDivide(Expr::Ptr in_lhs, Expr::Ptr in_rhs)
    : BinaryOperator(in_lhs, in_rhs)
{}



} } }
