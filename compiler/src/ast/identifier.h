#ifndef FLUSTER_COMPILER_AST_IDENTIFIER
#define FLUSTER_COMPILER_AST_IDENTIFIER

#include <string>
#include "util/ptrs.h"
#include "expr.h"
#include "name.h"

namespace fluster { namespace ast {



struct Identifier final
    : public Expr
{
    //// Construction
    Identifier() = default;
    Identifier(const std::string& in_name);

    //// Methods
    //const data::Construct::Ptr finalize() const override;

    //// Types
    using Ptr = util::Ptr<Identifier>;

private:
    //// Members
    const Name name;
};



} }

#endif //FLUSTER_COMPILER_AST_IDENTIFIER
