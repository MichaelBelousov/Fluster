#ifndef FLUSTER_COMPILER_AST_RESULT_HAVER
#define FLUSTER_COMPILER_AST_RESULT_HAVER

#include "util/ptrs.h"
#include "node.h"

// TODO: make Expr and Block derive from this

namespace fluster { namespace ast {



struct ResultHaver
    : public Node
{
    //// Types
    using Ptr = util::Ptr<ResultHaver>;
};



} }

#endif //FLUSTER_COMPILER_AST_RESULT_HAVER
