#ifndef FLUSTER_COMPILER_AST_OPS_POSTINCREMENT
#define FLUSTER_COMPILER_AST_OPS_POSTINCREMENT

#include "util/ptrs.h"
#include "ast/expr.h"
#include "operator.h"

namespace fluster { namespace ast { namespace ops {



struct PostIncrement final
    : public UnaryOperator
{
    //// Methods
    void print(std::ostream& os, unsigned indent_level) const override;

    llvm::Value* generateCode(GenerationContext& ctx) const final;

    //// Construction
    PostIncrement(Expr::Ptr in_operand);

    //// Types
    using Ptr = util::Ptr<PostIncrement>;

    //// Class Constants
    static const std::string tag;
    static const std::string symbol;
};



} } }

#endif //FLUSTER_COMPILER_AST_OPS_POSTINCREMENT
