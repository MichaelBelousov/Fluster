#ifndef FLUSTER_COMPILER_AST_LITS_STRING
#define FLUSTER_COMPILER_AST_LITS_STRING

#include <iostream>
#include "util/ptrs.h"
#include "atoms/types.h"
#include "ast/expr.h"

namespace fluster { namespace ast { namespace lits {



struct String final
    : public Expr
{
    //// Methods
    void print(std::ostream& os, unsigned indent_level) const override;

    llvm::Value* generateCode(GenerationContext& ctx) const override;

    //// Construction
    String(const atoms::String& in_value);

    //// Types
    using Ptr = util::Ptr<String>;

private:
    //// Members
    const atoms::String value;

};



} } }

#endif //FLUSTER_COMPILER_AST_LITS_STRING
