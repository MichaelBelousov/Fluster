#ifndef FLUSTER_COMPILER_AST_OPS_ASSIGN
#define FLUSTER_COMPILER_AST_OPS_ASSIGN

#include <memory>
#include "ast/node.h"
#include "operator.h"

namespace fluster { namespace ast { namespace ops {



struct Assign final
    : public BinaryOperator
{
    //// Methods
    //void
    //finalize(Node::Ptr in);

    //// Types
    using Ptr = std::shared_ptr<Assign>;
};



}; }; };

#endif //FLUSTER_COMPILER_AST_OPS_ASSIGN
