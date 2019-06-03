#ifndef FLUSTER_COMPILER_AST_OPS_ASSIGN
#define FLUSTER_COMPILER_AST_OPS_ASSIGN

#include "util/ptrs.h"
#include "ast/node.h"
#include "operator.h"

namespace fluster { namespace ast { namespace ops {



struct Assign final
    : public BinaryOperator
{
    //// Methods
    void print(std::ostream& os, unsigned indent_level) const override;

    llvm::Value* generateCode(GenerationContext& ctx) const final;

    //// Construction
    Assign(Expr::Ptr left, Expr::Ptr right);

    //// Types
    using Ptr = util::Ptr<Assign>;

    //// Class Constants
    static const std::string tag;
    static const std::string symbol;
};



} } }

#endif //FLUSTER_COMPILER_AST_OPS_ASSIGN
