#ifndef FLUSTER_COMPILER_AST_IF_STATEMENT
#define FLUSTER_COMPILER_AST_IF_STATEMENT

#include <memory>
#include "node.h"
#include "block.h"
#include "expr.h"
#include "util.h"

namespace fluster { namespace ast {



struct IfStatement final
    : public Node
{
    //// Types
    using Ptr = std::shared_ptr<IfStatement>;

    //// Methods
    static
    Node::Ptr
    empty();

    //// Construction
    IfStatement( Expr::Ptr in_cond
               , Node::Ptr in_then
               , Node::Ptr in_else = empty()
               );

    //// Members
    const Expr::Ptr cond;
    const Node::Ptr then;
    const Node::Ptr else_;
};



} }

#endif //FLUSTER_COMPILER_AST_IF_STATEMENT
