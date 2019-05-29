#ifndef FLUSTER_COMPILER_AST_OPS_POST_INCREMENT
#define FLUSTER_COMPILER_AST_OPS_POST_INCREMENT

#include <memory>
#include "ast/node.h"
#include "operator.h"

namespace fluster { namespace ast { namespace ops {



struct PostIncrement final
    : public UnaryOperator
{
    //// Methods
    //void
    //finalize(Node::Ptr in);

    //// Types
    using Ptr = std::shared_ptr<PostIncrement>;
};



}; }; };

#endif //FLUSTER_COMPILER_AST_OPS_POST_INCREMENT
