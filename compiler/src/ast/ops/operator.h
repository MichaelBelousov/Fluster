#ifndef FLUSTER_COMPILER_AST_OPERATOR
#define FLUSTER_COMPILER_AST_OPERATOR

// TODO: use a constant for the indentation amount
#define FLUSTER_COMPILER_OP_PRINT_IMPL(_class, _op_sym)                 \
    void _class::print(std::ostream& os, unsigned indent_level) const   \
    {                                                                   \
        for (unsigned i = 0; i < indent_level; ++i) os << " ";          \
        os << "<ops:'" << _op_sym << "'>" << std::endl;                 \
        for (const auto& operand : operands)                            \
            operand->print(os, indent_level+1);                         \
        for (unsigned i = 0; i < indent_level; ++i) os << " ";          \
        os << "</ops:'" << _op_sym << "'>" << std::endl;                \
    }

#include <array>
#include <vector>
#include <string>
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

template<int N>
struct NaryOperator
    : public Operator
{
protected:
    std::array<Expr::Ptr, N> operands;
};

template<int minimum_operands = 0>
struct VariateOperator
    : public Operator
{
    util::PreallocatedVector<Expr::Ptr, minimum_operands> operands;
};


struct UnaryOperator
    : public NaryOperator<1>
{
    UnaryOperator(Expr::Ptr in_operand);
    Expr::Ptr& operand = operands[0];
};


struct BinaryOperator
    : public NaryOperator<2>
{
    BinaryOperator( Expr::Ptr in_lhs
                  , Expr::Ptr in_rhs
                  );

    // TODO: make into a function so they can be optimized out?
    Expr::Ptr& lhs;
    Expr::Ptr& rhs;
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
