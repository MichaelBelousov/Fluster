#include "square_root.h"

namespace fluster { namespace ast { namespace ops {


//// Class Constants

const std::string SquareRoot::tag = "square_root";
const std::string SquareRoot::symbol = "^/";

//// Methods

llvm::Value*
SquareRoot::
generateCode(GenerationContext& ctx) const
{
    return _generateCode<SquareRoot::tag>(ctx);
}

void
SquareRoot::
print(std::ostream& os, unsigned indent_level) const
{
    _print<SquareRoot::symbol>(os, indent_level);
}

//// Construction

SquareRoot::
SquareRoot(Expr::Ptr in_operand)
    : UnaryOperator(in_operand)
{}



} } }
