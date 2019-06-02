#include "node.h"
#include "if_statement.h"

namespace fluster { namespace ast {

//// Methods

Node::Ptr
IfStatement::
empty()
{
    return IfStatement::Ptr::make().castUp<Node>();
}

void
IfStatement::
print(std::ostream& os, unsigned indent_level) const
{
    for (unsigned i = 0; i < indent_level; ++i) os << " ";
    os << "<if>" << std::endl;

    // XXX: debug this for preconditions
    if (cond) cond->print(os, indent_level+1);
    if (then) then->print(os, indent_level+1);
    if (else_) else_->print(os, indent_level+1);
    
    for (unsigned i = 0; i < indent_level; ++i) os << " ";
    os << "</if>" << std::endl;
}

//// Construction

IfStatement::
IfStatement( Expr::Ptr in_cond
           , Node::Ptr in_then
           , Node::Ptr in_else
           )
    : cond(in_cond)
    , then(in_then)
    , else_(in_else)
{}



} }
