#ifndef FLUSTER_COMPILER_AST_LITS_FLOAT
#define FLUSTER_COMPILER_AST_LITS_FLOAT

#include <memory>
#include "data/construct.h"
#include "ast/expr.h"

namespace fluster { namespace ast { namespace lits {



struct Float final
    : public Expr
{
    //// Methods
    //const data::Construct::Ptr finalize() const final;

    //// Construction
    Float();

    //// Types
    using Ptr = std::shared_ptr<Float>;
};



}; }; };

#endif //FLUSTER_COMPILER_AST_LITS_FLOAT
