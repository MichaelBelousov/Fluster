#ifndef FLUSTER_COMPILER_AST_OPS_MULTIPLY
#define FLUSTER_COMPILER_AST_OPS_MULTIPLY

#include <memory>
#include "ast/node.h"
#include "operator.h"

namespace fluster { namespace ast { namespace ops {



struct Multiply final
    : public BinaryOperator
{
    //// Methods
    //void
    //finalize(Node::Ptr in);

    //// Types
    using Ptr = std::shared_ptr<Multiply>;
};



}; }; };

#endif //FLUSTER_COMPILER_AST_OPS_MULTIPLY
