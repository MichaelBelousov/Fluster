#include "postdecrement.h"

namespace fluster { namespace ast { namespace ops {



//// Class Constants

const std::string PostDecrement::tag = "postdecrement";
const std::string PostDecrement::symbol = "--";

//// Methods

llvm::Value*
PostDecrement::
generateCode(GenerationContext& ctx) const
{
    return _generateCode<PostDecrement::tag>(ctx);
}

void
PostDecrement::
print(std::ostream& os, unsigned indent_level) const
{
    _print<PostDecrement::symbol>(os, indent_level);
}

//// Construction

PostDecrement::
PostDecrement(Expr::Ptr in_operand)
    : UnaryOperator(in_operand)
{}



} } }
