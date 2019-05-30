#ifndef FLUSTER_COMPILER_AST_LITS_BITS
#define FLUSTER_COMPILER_AST_LITS_BITS

#include <memory>
#include "atoms/types.h"
#include "ast/expr.h"

namespace fluster { namespace ast { namespace lits {



struct Bits final
    : public Expr
{
    //// Methods
    //const data::Construct::Ptr finalize() const final;

    //// Construction
    Bits(const atoms::BitArray& in_value);

    //// Types
    using Ptr = std::shared_ptr<Bits>;

private:
    //// Members
    const atoms::BitArray value;
};



} } }

#endif //FLUSTER_COMPILER_AST_LITS_BITS
