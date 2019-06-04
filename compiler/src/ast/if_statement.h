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
    void commit(db::ProgramDatabase& db) const override;

    llvm::Value* generateCode(GenerationContext& ctx) const override;

    void print(std::ostream& os, unsigned indent_level) const override;

    //// Class functions
    static Node::Ptr empty();

    //// Construction
    IfStatement() = default;
    IfStatement( Expr::Ptr in_cond
               , Node::Ptr in_then
               , Node::Ptr in_else = empty()
               );

    //// Members
    // TODO: make the then and else links blocks/expr nodes
    const Expr::Ptr cond;
    const Node::Ptr then;
    const Node::Ptr else_;
};



} }

#endif //FLUSTER_COMPILER_AST_IF_STATEMENT
