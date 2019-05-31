#include "power.h"

namespace fluster { namespace ast { namespace ops {



Power::
Power(Expr::Ptr in_lhs, Expr::Ptr in_rhs)
    : BinaryOperator("^", in_lhs, in_rhs)
{}



} } }
