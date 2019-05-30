#include "int_divide.h"

namespace fluster { namespace ast { namespace ops {



IntDivide::
IntDivide(Expr::Ptr in_lhs, Expr::Ptr in_rhs)
{
    lhs = in_lhs;
    rhs = in_rhs;
}



} } }
