#ifndef FLUSTER_COMPILER_AST_LITS_FLOAT
#define FLUSTER_COMPILER_AST_LITS_FLOAT

#include <utility>
#include <iostream>
#include <llvm/ADT/APFloat.h>
#include "util/ptrs.h"
#include "ast/expr.h"
#include "db/primitives.h"

namespace fluster { namespace ast { namespace lits {



struct Float final
    : public Expr
{
    //// Methods
    void commit(db::ProgramDatabase& db) const override;
    llvm::Value* generateCode(GenerationContext& ctx) const override;
    void print(std::ostream& os, unsigned indent_level) const override;

    //// Construction
    template<typename ...Args>
    Float(Args&& ...args)
        : Expr(db::f64)
        , value(std::forward<Args>(args)...)
    {}

    //// Types
    using Ptr = util::Ptr<Float>;

private:
    //// Members
    const llvm::APFloat value;
};



} } }  //namespace fluster::ast::lits

#endif //FLUSTER_COMPILER_AST_LITS_FLOAT
