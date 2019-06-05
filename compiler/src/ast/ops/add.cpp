#include "add.h"
#include "db/type.h"

namespace fluster { namespace ast { namespace ops {



//// Class Constants

const std::string Add::tag = "add";
const std::string Add::symbol = "+";

//// Methods

void
Add::
commit(db::ProgramDatabase& db) const
{
    // XXX: horrible, need to create committed objects with the asserted type
    *const_cast<db::Type::Ptr*>(&result_type) =
        db.operations.at(Name("add"))->return_type;
}

llvm::Value*
Add::
generateCode(GenerationContext& ctx) const
{
    return _generateCode<Add::tag>(ctx);
}

void
Add::
print(std::ostream& os, unsigned indent_level) const
{
    _print<Add::symbol>(os, indent_level);
}

//// Construction

Add::
Add(Expr::Ptr in_lhs, Expr::Ptr in_rhs)
    : BinaryOperator(in_lhs, in_rhs)
{}



} } }  //namespace fluster::ast::ops
