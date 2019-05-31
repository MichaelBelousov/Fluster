#ifndef FLUSTER_COMPILER_AST_OPERATOR
#define FLUSTER_COMPILER_AST_OPERATOR

#include <array>
#include <vector>
#include <iostream>
#include "util/ptrs.h"
#include "ast/expr.h"
#include "util/preallocated_vector.h"

namespace fluster { namespace ast { namespace ops {



struct Operator
    : public Expr
{
    using Ptr = util::Ptr<Operator>;
};

template< int N
        >
struct NaryOperator
    : public Operator
{
    std::array<Expr::Ptr, N> operands;

    void print(std::ostream& os, unsigned indent_level) override
    {
        for (unsigned i = 0; i < indent_level; ++i) os << " ";
        os << "<ops:" << ">" << std::endl;

        for (const auto& op : operands)
            op->print(os, indent_level+2);  //TODO: make 2 a constant, indenting

        for (unsigned i = 0; i < indent_level; ++i) os << " ";
        os << "</ops:" << ">" << std::endl;
    }
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
