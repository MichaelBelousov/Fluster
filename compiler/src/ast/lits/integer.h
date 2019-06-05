#ifndef FLUSTER_COMPILER_AST_LITS_INTEGER
#define FLUSTER_COMPILER_AST_LITS_INTEGER

#include <utility>
#include <iostream>
#include <llvm/ADT/APInt.h>
#include "util/ptrs.h"
#include "ast/expr.h"
#include "db/primitives.h"

namespace fluster { namespace ast { namespace lits {



struct Integer final
    : public Expr
{
    //// Methods
    void commit(db::ProgramDatabase& db) const override;
    llvm::Value* generateCode(GenerationContext& ctx) const override;
    void print(std::ostream& os, unsigned indent_level) const override;

    //// Construction
    template<typename ...Args>
    Integer(Args&& ...args)
        : Expr(db::i64)
        , value(std::forward<Args>(args)...)
    {}

    //// Types
    using Ptr = util::Ptr<Integer>;

private:
    //// Members
    const llvm::APInt value;
};



} } }  //namespace fluster::ast::lits

#endif //FLUSTER_COMPILER_AST_LITS_INTEGER
