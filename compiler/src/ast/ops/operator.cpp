#include "operator.h"

namespace fluster { namespace ast { namespace ops {



UnaryOperator::
UnaryOperator( const std::string& in_op_sym
             , Expr::Ptr in_operand
             )
    : NaryOperator<1>(in_op_sym)
    , operand(in_operand)
{}


BinaryOperator::
BinaryOperator( const std::string& in_op_sym
              , Expr::Ptr in_lhs
              , Expr::Ptr in_rhs
              )
    : NaryOperator<2>(in_op_sym)
    , lhs(in_lhs)
    , rhs(in_rhs)
{}



} } }
