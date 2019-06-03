#ifndef FLUSTER_COMPILER_AST_OPS_SUBTRACT
#define FLUSTER_COMPILER_AST_OPS_SUBTRACT

#include "util/ptrs.h"
#include "ast/node.h"
#include "operator.h"

namespace fluster { namespace ast { namespace ops {



struct Subtract final
    : public BinaryOperator
{
    //// Methods
    void print(std::ostream& os, unsigned indent_level) const override;

    llvm::Value* generateCode(GenerationContext& ctx) const final;

    //// Construction
    Subtract( Expr::Ptr left_operand
            , Expr::Ptr right_operand
            );

    //// Types
    using Ptr = util::Ptr<Subtract>;

    //// Class Constants
    static const std::string tag;
    static const std::string symbol;
};



} } }

#endif //FLUSTER_COMPILER_AST_OPS_SUBTRACT
