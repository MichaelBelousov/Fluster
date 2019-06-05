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

    //// Construction
    Expr() = default;
    Expr(db::Type::Ptr in_result_type);

    //// Members
    db::Type::Ptr result_type;
    // XXX: result_type is set once the code is commited
    // should be done using a type, could be done using a flag
};



} }

#endif //FLUSTER_COMPILER_AST_EXPR
