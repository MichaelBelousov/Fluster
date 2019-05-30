#ifndef FLUSTER_COMPILER_AST_LITS_INTEGER
#define FLUSTER_COMPILER_AST_LITS_INTEGER

#include <memory>
#include "atoms/types.h"
#include "ast/expr.h"

namespace fluster { namespace ast { namespace lits {



struct Integer final
    : public Expr
{
    //// Methods
    //const data::Construct::Ptr finalize() const final;

    //// Construction
    Integer(atoms::NaturalNum in_value);

    //// Types
    using Ptr = std::shared_ptr<Integer>;

private:
    //// Members
    const atoms::NaturalNum value;
};



}; }; };

#endif //FLUSTER_COMPILER_AST_LITS_INTEGER
