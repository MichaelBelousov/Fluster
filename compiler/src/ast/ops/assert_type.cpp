#include "assert_type.h"

namespace fluster { namespace ast { namespace ops {



//// Class Constants

const std::string AssertType::tag = "type_assert";
const std::string AssertType::symbol = ":";

//// Methods

llvm::Value*
AssertType::
generateCode(GenerationContext& ctx) const
{
    return _generateCode<AssertType::tag>(ctx);
}

void
AssertType::
print(std::ostream& os, unsigned indent_level) const
{
    _print<AssertType::symbol>(os, indent_level);
}

//// Construction


AssertType::
AssertType(Expr::Ptr in_lhs, Expr::Ptr in_rhs)
    : BinaryOperator(in_lhs, in_rhs)
{}



} } }
