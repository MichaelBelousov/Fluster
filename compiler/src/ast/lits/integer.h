#ifndef FLUSTER_COMPILER_AST_LITS_INTEGER
#define FLUSTER_COMPILER_AST_LITS_INTEGER

#include <iostream>
#include <llvm/ADT/APInt.h>
#include "util/ptrs.h"
#include "ast/expr.h"

namespace fluster { namespace ast { namespace lits {



struct Integer final
    : public Expr
{
    //// Methods
    void print(std::ostream& os, unsigned indent_level) const override;

    llvm::Value* generateCode(GenerationContext& ctx) const;

    //// Construction
    Integer(const llvm::APInt& in_value);

    //// Types
    using Ptr = util::Ptr<Integer>;

private:
    //// Members
    const llvm::APInt value;
};



} } }

#endif //FLUSTER_COMPILER_AST_LITS_INTEGER
