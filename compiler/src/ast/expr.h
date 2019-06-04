#ifndef FLUSTER_COMPILER_AST_EXPR
#define FLUSTER_COMPILER_AST_EXPR

#include "util/ptrs.h"
#include "db/type.h"
#include "node.h"

namespace fluster { namespace ast {



struct Expr
    : public Node
{
    //// Types
    using Ptr = util::Ptr<Expr>;

    //// Members
    const db::Type::Ptr result_type;
};



} }

#endif //FLUSTER_COMPILER_AST_EXPR
