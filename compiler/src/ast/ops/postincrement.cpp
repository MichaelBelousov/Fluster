#include "postincrement.h"

namespace fluster { namespace ast { namespace ops {



PostIncrement::
PostIncrement(Expr::Ptr in_operand)
{
    operand = in_operand;
}



} } }
