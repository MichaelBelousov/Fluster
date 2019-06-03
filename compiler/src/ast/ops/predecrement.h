#ifndef FLUSTER_COMPILER_AST_OPS_PREDECREMENT
#define FLUSTER_COMPILER_AST_OPS_PREDECREMENT

#include "util/ptrs.h"
#include "ast/expr.h"
#include "operator.h"

namespace fluster { namespace ast { namespace ops {



struct PreDecrement final
    : public UnaryOperator
{
    //// Methods
    void print(std::ostream& os, unsigned indent_level) const override;

    llvm::Value* generateCode(GenerationContext& ctx) const final;

    //// Construction
    PreDecrement(Expr::Ptr in_operand);

    //// Types
    using Ptr = util::Ptr<PreDecrement>;

    //// Class Constants
    static const std::string tag;
    static const std::string symbol;
};



} } }

#endif //FLUSTER_COMPILER_AST_OPS_PREDECREMENT
