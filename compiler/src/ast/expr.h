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

    //// Methods
    void print(std::ostream& os, unsigned indent_level) const override;

    //// Members
    const db::Type::Ptr result_type;  //needs to be finalized...?

    //virtual begin //TODO: iterate over children?
    //virtual end
};



} }

#endif //FLUSTER_COMPILER_AST_EXPR
