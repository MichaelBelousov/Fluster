#ifndef FLUSTER_COMPILER_AST_OPS_ROOT
#define FLUSTER_COMPILER_AST_OPS_ROOT

#include <memory>
#include "ast/node.h"
#include "operator.h"

namespace fluster { namespace ast {



struct Root final
    : public BinaryOperator
{
    //// Methods
    //void
    //finalize(Node::Ptr in);

    //// Types
    using Ptr = std::shared_ptr<Root>;
};



}; };

#endif //FLUSTER_COMPILER_AST_OPS_ROOT
