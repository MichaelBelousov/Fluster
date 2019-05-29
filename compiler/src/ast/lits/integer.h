#ifndef FLUSTER_COMPILER_AST_LITS_INTEGER
#define FLUSTER_COMPILER_AST_LITS_INTEGER

#include <memory>
#include "data/construct.h"
#include "expr.h"

namespace fluster { namespace ast { namespace lits {



struct Integer final
    : public Expr
{
    //// Types
    using Ptr = std::shared_ptr<Integer>;

    //// Construction
    Integer();

    //// Methods
    const data::Construct::Ptr finalize() const final;
};



}; }; };

#endif //FLUSTER_COMPILER_AST_LITS_INTEGER
