#include "postincrement.h"

namespace fluster { namespace ast { namespace ops {



//// Class Constants

const std::string PostIncrement::tag = "postincrement";
const std::string PostIncrement::symbol = "++";

//// Methods

llvm::Value*
PostIncrement::
generateCode(GenerationContext& ctx) const
{
    return _generateCode<PostIncrement::tag>(ctx);
}

void
PostIncrement::
print(std::ostream& os, unsigned indent_level) const
{
    _print<PostIncrement::symbol>(os, indent_level);
}

//// Construction

PostIncrement::
PostIncrement(Expr::Ptr in_operand)
    : UnaryOperator(in_operand)
{}



} } }
