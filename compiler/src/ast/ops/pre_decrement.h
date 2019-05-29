#ifndef FLUSTER_COMPILER_AST_OPS_PRE_DECREMENT
#define FLUSTER_COMPILER_AST_OPS_PRE_DECREMENT

#include <memory>
#include "ast/node.h"
#include "operator.h"

namespace fluster { namespace ast {



struct PreDecrement final
    : public UnaryOperator
{
    //// Methods
    //void
    //finalize(Node::Ptr in);

    //// Types
    using Ptr = std::shared_ptr<PreDecrement>;
};



}; };

#endif //FLUSTER_COMPILER_AST_OPS_PRE_DECREMENT
