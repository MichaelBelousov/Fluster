#include "assign.h"

namespace fluster { namespace ast { namespace ops {



Assign::
Assign(Expr::Ptr in_lhs, Expr::Ptr in_rhs)
    : BinaryOperator("=", in_lhs, in_rhs)
{}



} } }
