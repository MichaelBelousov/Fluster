#ifndef FLUSTER_COMPILER_AST_BASE
#define FLUSTER_COMPILER_AST_BASE

/* The fluster AST holds mutable, in-progress versions
 * of each fluster construct, as they are being read
 * and validated, so each 
 */

#include <array>
#include <string>
#include <vector>
#include "util.h"

namespace fluster { namespace ast {



struct Node
{
    using Ptr = std::shared_ptr<Node>;
    const Construct finalize() const = 0;
};

using Name = const std::string;

struct Def
  : public Node
{
    using Ptr = std::shared_ptr<Def>;
    //ScopePtr _outer;
};

using Statement = Def;

struct NamedDef
  : public Def
{
    Name name;
};

struct Expr
  : public Node
{
};

using Expression = Expr;

struct Identifier : public Expr {
    Name name;
};


template<int N>
struct NaryExpr : public Expr {};

struct Operator : public Expr {};

template<int N>
struct NaryOperator : public Operator {
    std::array<Expr::Ptr, N> operands;
};

using UnaryOperator = NaryOperator<1>;

struct BinaryOperator : public NaryOperator<2> {
    Expr::Ptr leftOperand() { return operands[0]; }
    Expr::Ptr rightOperand() { return operands[1]; }
};

struct TernaryOperator : public NaryOperator<3> {
    Expr::Ptr firstOperand() { return operands[0]; }
    Expr::Ptr secondOperand() { return operands[1]; }
    Expr::Ptr thirdOperand() { return operands[2]; }
};

struct InvokeOperation : public Operator {
    std::vector<Expr::Ptr> arguments;
    Expr::Ptr invokee;
};



}; };

#endif //FLUSTER_COMPILER_AST_BASE
