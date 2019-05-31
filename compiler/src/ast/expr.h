#ifndef FLUSTER_COMPILER_AST_EXPR
#define FLUSTER_COMPILER_AST_EXPR

/* The fluster data holds immutable, finalized versions
 * of each fluster construct, in a code base, after they
 * have been parsed, and its usage has been semantically validated
 */

#include "util/ptrs.h"
#include "node.h"

namespace fluster { namespace ast {



struct Expr
    : public Node
{
    //// Types

    using Ptr = util::Ptr<Expr>;

    //begin //TODO: iterate over expr underlying?
    //end
};



} }

#endif //FLUSTER_COMPILER_AST_EXPR
