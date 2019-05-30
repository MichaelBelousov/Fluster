#ifndef FLUSTER_COMPILER_AST_LITS_BYTES
#define FLUSTER_COMPILER_AST_LITS_BYTES

#include "util/ptr.h"
#include "atoms/types.h"
#include "ast/expr.h"

namespace fluster { namespace ast { namespace lits {



struct Bytes final
    : public Expr
{
    //// Methods
    //const data::Construct::Ptr finalize() const final;

    //// Construction
    Bytes(const atoms::ByteArray& in_value);

    //// Types
    using Ptr = util::Ptr<Bytes>;

private:
    //// Members
    const atoms::ByteArray value;
};



} } }

#endif //FLUSTER_COMPILER_AST_LITS_BYTES
