#ifndef FLUSTER_COMPILER_AST_OPERATOR
#define FLUSTER_COMPILER_AST_OPERATOR

#include <array>
#include <vector>
#include <memory>
#include "ast/expr.h"
#include "util.h"

namespace fluster { namespace ast { namespace ops {



struct Operator
    : public Expr
{
    using Ptr = std::shared_ptr<Operator>;
};

template< int N
        >
struct NaryOperator
    : public Operator
{
    std::array<Expr::Ptr, N> operands;
};

template< int minimum_operands = 0
        >
struct VariateOperator
    : public Operator
{
    util::PreallocatedVector<Expr::Ptr, minimum_operands> operands;
};


struct UnaryOperator
    : public NaryOperator<1>
{
    //optimize out?
    /*constexpr*/ Expr::Ptr& operand = operands[0];
};


struct BinaryOperator
    : public NaryOperator<2>
{
    Expr::Ptr& lhs = operands[0];
    Expr::Ptr& rhs = operands[1];
};

struct TernaryOperator
    : public NaryOperator<3>
{
    Expr::Ptr& first  = operands[0];
    Expr::Ptr& second = operands[1];
    Expr::Ptr& third  = operands[2];
};

struct InvokeOperation
    : public VariateOperator<1>
{
    Expr::Ptr& invokee = operands[0];  //XXX: invalid during construction?
    //Span<operands, 1>& arguments;
};



} } }

#endif //FLUSTER_COMPILER_AST_OPERATOR
