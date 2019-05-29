#ifndef FLUSTER_COMPILER_DATA_BASE
#define FLUSTER_COMPILER_DATA_BASE

/* The fluster data holds immutable, finalized versions
 * of each fluster construct, in a code base, after they
 * have been parsed, and its usage has been semantically validated
 */

#include <array>
#include <string>
#include <vector>
#include <memory>
#include "util.h"

namespace fluster { namespace ast {



struct Node
    : public std::enable_shared_from_this<Node>
{
    //// Types
    
    using Ptr = std::shared_ptr<Node>;

    //// Construction

    Node(Node::Ptr outer);

    //// Members
    
    const std::weak_ptr<Node> outer;

    //// Methods

    // finalize this node, producing it's internally consistent construct
    const data::Construct::Ptr finalize() const = 0;

    // make a child of this node
    template<typename T, typename ...Args>
    Node::Ptr makeChild(Args&& ...args); 

    // make an AST root node
    static Node::Ptr makeRoot();
};

#include "node.tpp"

template<typename T, typename ...Args>
Node::Ptr
Node::
makeChild(Args&& ...args)
{
    Node::Ptr result =
        new T( this->shared_from_this()
             , std::forward<Args>(args)...
             );
    return result;
}


struct Name
{
    Name(const std::string& in_value);
    const std::string value;
    static const bool validate(const std::string& in);
};

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

#endif //FLUSTER_COMPILER_DATA_BASE
