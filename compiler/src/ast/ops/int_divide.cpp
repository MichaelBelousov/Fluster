#include "int_divide.h"

namespace fluster { namespace ast { namespace ops {



IntDivide::
IntDivide(Expr::Ptr in_lhs, Expr::Ptr in_rhs)
    : BinaryOperator(in_lhs, in_rhs)
{}

FLUSTER_COMPILER_OP_PRINT_IMPL(IntDivide, "//")



} } }
