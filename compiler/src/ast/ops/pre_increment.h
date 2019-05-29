#ifndef FLUSTER_COMPILER_AST_OPS_PRE_INCREMENT
#define FLUSTER_COMPILER_AST_OPS_PRE_INCREMENT

#include <memory>
#include "ast/node.h"
#include "operator.h"

namespace fluster { namespace ast { namespace ops {



struct PreIncrement final
    : public UnaryOperator
{
    //// Methods
    //void
    //finalize(Node::Ptr in);

    //// Types
    using Ptr = std::shared_ptr<PreIncrement>;
};



}; }; };

#endif //FLUSTER_COMPILER_AST_OPS_PRE_INCREMENT
