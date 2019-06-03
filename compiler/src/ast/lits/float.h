#ifndef FLUSTER_COMPILER_AST_LITS_FLOAT
#define FLUSTER_COMPILER_AST_LITS_FLOAT

#include <iostream>
#include "llvm/ADT/APFloat.h"
#include "util/ptrs.h"
#include "ast/expr.h"

namespace fluster { namespace ast { namespace lits {



struct Float final
    : public Expr
{
    //// Methods
    void print(std::ostream& os, unsigned indent_level) const override;

    llvm::Value* generateCode( const llvm::LLVMContext& ctx
                             , const llvm::IRBuilder<>& builder
                             ) const override;

    //// Construction
    Float(const llvm::APFloat& in_value);

    //// Types
    using Ptr = util::Ptr<Float>;

private:
    //// Members
    const llvm::APFloat value;
};



} } }  //namespace fluster::ast::lits

#endif //FLUSTER_COMPILER_AST_LITS_FLOAT
