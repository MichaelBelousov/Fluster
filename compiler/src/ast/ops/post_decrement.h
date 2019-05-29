#ifndef FLUSTER_COMPILER_AST_OPS_POST_DECREMENT
#define FLUSTER_COMPILER_AST_OPS_POST_DECREMENT

#include <memory>
#include "ast/node.h"
#include "operator.h"

namespace fluster { namespace ast { namespace ops {



struct PostDecrement final
    : public UnaryOperator
{
    //// Methods
    //void
    //finalize(Node::Ptr in);

    //// Types
    using Ptr = std::shared_ptr<PostDecrement>;
};



}; }; };

#endif //FLUSTER_COMPILER_AST_OPS_POST_DECREMENT
