#ifndef FLUSTER_COMPILER_AST_OPERATOR
#define FLUSTER_COMPILER_AST_OPERATOR

/* The fluster data holds immutable, finalized versions
 * of each fluster construct, in a code base, after they
 * have been parsed, and its usage has been semantically validated
 */

#include <array>
#include <vector>
#include <memory>
#include "expr.h"
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
    PreallocatedVector<Expr::Ptr, minimum_operands> operands;
};


struct UnaryOperator
    : public NaryOperator<1>
{
    constexpr Expr::Ptr& operand = operands[0];
};


struct BinaryOperator
    : public NaryOperator<2>
{
    constexpr Expr::Ptr& lhs = operands[0];
    constexpr Expr::Ptr& rhs = operands[1];
};

struct TernaryOperator
    : public NaryOperator<3>
{
    constexpr Expr::Ptr& first  = operands[0];
    constexpr Expr::Ptr& second = operands[1];
    constexpr Expr::Ptr& third  = operands[2];
};

struct InvokeOperation
    : public VariateOperator<1>
{
    constexpr Span<operands, 1>& arguments;
    constexpr Expr::Ptr& invokee = operands[0];  //XXX: invalid during construction
};



}; }; };

#endif //FLUSTER_COMPILER_AST_OPERATOR
