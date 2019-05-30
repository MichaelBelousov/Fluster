#include "postdecrement.h"

namespace fluster { namespace ast { namespace ops {



PostDecrement::
PostDecrement(Expr::Ptr in_operand)
{
    operand = in_operand;
}



} } }
