#include "subtract.h"

namespace fluster { namespace ast { namespace ops {



Subtract::
Subtract(Expr::Ptr in_lhs, Expr::Ptr in_rhs)
    : BinaryOperator(in_lhs, in_rhs)
{}

FLUSTER_COMPILER_OP_PRINT_IMPL(Subtract, "-")



} } }
