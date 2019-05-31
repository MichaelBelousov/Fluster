#ifndef FLUSTER_COMPILER_AST_EXPR
#define FLUSTER_COMPILER_AST_EXPR

#include "util/ptrs.h"
#include "node.h"

namespace fluster { namespace ast {



struct Expr
    : public Node
{
    //// Types
    using Ptr = util::Ptr<Expr>;

    void print(std::ostream& os, unsigned indent_level) override;

    //begin //TODO: iterate over children?
    //end
};



} }

#endif //FLUSTER_COMPILER_AST_EXPR
