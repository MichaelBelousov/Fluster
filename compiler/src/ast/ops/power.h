#ifndef FLUSTER_COMPILER_AST_OPS_POWER
#define FLUSTER_COMPILER_AST_OPS_POWER

#include <memory>
#include "ast/node.h"
#include "operator.h"

namespace fluster { namespace ast {



struct Power final
    : public BinaryOperator
{
    //// Methods
    //void
    //finalize(Node::Ptr in);

    //// Types
    using Ptr = std::shared_ptr<Power>;
};



}; };

#endif //FLUSTER_COMPILER_AST_OPS_POWER
