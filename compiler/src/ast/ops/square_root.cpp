#include "square_root.h"

namespace fluster { namespace ast { namespace ops {



SquareRoot::
SquareRoot(Expr::Ptr in_operand)
    : UnaryOperator(in_operand)
{}

FLUSTER_COMPILER_OP_PRINT_IMPL(SquareRoot, "^/")



} } }
