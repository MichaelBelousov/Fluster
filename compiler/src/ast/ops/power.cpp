#include "power.h"

namespace fluster { namespace ast { namespace ops {



Power::
Power(Expr::Ptr in_lhs, Expr::Ptr in_rhs)
{
    lhs = in_lhs;
    rhs = in_rhs;
}



} } }
