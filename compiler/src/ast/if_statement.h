#ifndef FLUSTER_COMPILER_AST_IF_STATEMENT
#define FLUSTER_COMPILER_AST_IF_STATEMENT

#include "util/ptrs.h"
#include "node.h"
#include "expr.h"

namespace fluster { namespace ast {



struct IfStatement final
    : public Node
{
    //// Types
    using Ptr = util::Ptr<IfStatement>;

    //// Methods
    static
    Node::Ptr
    empty();

    llvm::Value* generateCode(GenerationContext& ctx) const final;

    void print(std::ostream& os, unsigned indent_level) const override;

    // TODO: make the then and else links blocks

    //// Construction
    IfStatement() = default;
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
