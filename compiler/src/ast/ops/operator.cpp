#include "operator.h"
#include "db/type.h"

namespace fluster { namespace ast { namespace ops {



UnaryOperator::
UnaryOperator(Expr::Ptr in_operand)
    : operand(operands[0])
{
    operand = in_operand;
}


BinaryOperator::
BinaryOperator( Expr::Ptr in_lhs
              , Expr::Ptr in_rhs
              )
    : lhs(operands[0])
    , rhs(operands[1])
{
    lhs = in_lhs;
    rhs = in_rhs;
}



} } }
