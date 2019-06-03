#ifndef FLUSTER_COMPILER_AST_OPS_SEQUENCE
#define FLUSTER_COMPILER_AST_OPS_SEQUENCE

#include "util/ptrs.h"
#include "ast/expr.h"
#include "operator.h"

namespace fluster { namespace ast { namespace ops {


// TODO: not really an operator, move out to some more specific folder

struct Sequence final
    : public BinaryOperator
{
    //// Methods
    void print(std::ostream& os, unsigned indent_level) const override;

    llvm::Value* generateCode(GenerationContext& ctx) const final;

    //// Construction
    Sequence(Expr::Ptr in_lhs, Expr::Ptr in_rhs);

    //// Types
    using Ptr = util::Ptr<Sequence>;

    //// Class Constants
    static const std::string tag;
    static const std::string symbol;
};



} } }

#endif //FLUSTER_COMPILER_AST_OPS_SEQUENCE
