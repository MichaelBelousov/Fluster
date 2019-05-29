#ifndef FLUSTER_COMPILER_AST_IF_STATEMENT
#define FLUSTER_COMPILER_AST_IF_STATEMENT

/* The fluster data holds immutable, finalized versions
 * of each fluster construct, in a code base, after they
 * have been parsed, and its usage has been semantically validated
 */

#include <memory>
#include "node.h"
#include "util.h"

namespace fluster { namespace ast {



struct IfStatement final
    : public Node
{
    //// Types
    using Ptr = std::shared_ptr<IfStatement>;

    //// Methods
    static
    IfStatement::Ptr
    empty();

    //// Construction
    IfStatement( Expr::Ptr in_cond
               , Node::Ptr in_then
               , Node::Ptr in_else
               );

    //// Members
    const Expr::Ptr cond;
    const Block::Ptr then;
    const Block::Ptr else_;
};



}; };

#endif //FLUSTER_COMPILER_AST_IF_STATEMENT
