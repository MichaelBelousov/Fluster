#ifndef FLUSTER_COMPILER_AST_EXPR
#define FLUSTER_COMPILER_AST_EXPR

/* The fluster data holds immutable, finalized versions
 * of each fluster construct, in a code base, after they
 * have been parsed, and its usage has been semantically validated
 */

#include <memory>
#include "node.h"
#include "util.h"

namespace fluster { namespace ast {



struct Expr
    : public Node
{
    //// Types

    using Ptr = std::shared_ptr<Expr>;

    //begin //TODO: iterate over expr underlying?
    //end
};



}; };

#endif //FLUSTER_COMPILER_AST_EXPR
