#ifndef FLUSTER_COMPILER_AST_LITS_INTEGER
#define FLUSTER_COMPILER_AST_LITS_INTEGER

#include "util/ptr.h"
#include "atoms/types.h"
#include "ast/expr.h"

namespace fluster { namespace ast { namespace lits {



struct Integer final
    : public Expr
{
    //// Methods
    //const data::Construct::Ptr finalize() const final;

    //// Construction
    Integer(const atoms::Integer& in_value);

    //// Types
    using Ptr = util::Ptr<Integer>;

private:
    //// Members
    const atoms::Integer value;
};



} } }

#endif //FLUSTER_COMPILER_AST_LITS_INTEGER