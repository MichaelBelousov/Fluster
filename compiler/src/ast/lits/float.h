#ifndef FLUSTER_COMPILER_AST_LITS_FLOAT
#define FLUSTER_COMPILER_AST_LITS_FLOAT

#include <memory>
#include "data/construct.h"
#include "expr.h"

namespace fluster { namespace ast { namespace lits {



struct Float final
    : public Expr
{
    //// Types
    using Ptr = std::shared_ptr<Float>;

    //// Construction
    Float();

    //// Methods
    const data::Construct::Ptr finalize() const final;
};



}; }; };

#endif //FLUSTER_COMPILER_AST_LITS_FLOAT
