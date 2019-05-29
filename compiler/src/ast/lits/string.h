#ifndef FLUSTER_COMPILER_AST_LITS_STRING
#define FLUSTER_COMPILER_AST_LITS_STRING

#include <memory>
#include "data/construct.h"
#include "expr.h"

namespace fluster { namespace ast { namespace lits {



struct String final
    : public Expr
{
    //// Types
    using Ptr = std::shared_ptr<String>;

    //// Construction
    String();

    //// Methods
    //const data::Construct::Ptr finalize() const final;
};



}; }; };

#endif //FLUSTER_COMPILER_AST_LITS_STRING
