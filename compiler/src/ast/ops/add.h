#ifndef FLUSTER_COMPILER_AST_OPS_ADD
#define FLUSTER_COMPILER_AST_OPS_ADD

#include <memory>
#include "ast/node.h"
#include "operator.h"

namespace fluster { namespace ast {



struct Add final
    : public BinaryOperator
{
    //// Methods
    //void
    //finalize(Node::Ptr in);

    //// Types
    using Ptr = std::shared_ptr<Add>;
};



}; };

#endif //FLUSTER_COMPILER_AST_OPS_ADD
