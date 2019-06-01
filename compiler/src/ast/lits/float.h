#ifndef FLUSTER_COMPILER_AST_LITS_FLOAT
#define FLUSTER_COMPILER_AST_LITS_FLOAT

#include "util/ptrs.h"
#include "atoms/types.h"
#include "ast/expr.h"

namespace fluster { namespace ast { namespace lits {



struct Float final
    : public Expr
{
    //// Methods
    void print(std::ostream& os, unsigned indent_level) const override;

    //const data::Construct::Ptr finalize() const final;

    //// Construction
    Float(const atoms::Rational& in_value);

    //// Types
    using Ptr = util::Ptr<Float>;

private:
    //// Members
    const atoms::Rational value;
};



} } }  //namespace fluster::ast::lits

#endif //FLUSTER_COMPILER_AST_LITS_FLOAT
