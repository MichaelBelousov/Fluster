#include <memory>
#include "if_statement.h"

namespace fluster { namespace ast {

//// Methods

Node::Ptr
IfStatement::
empty()
{
    return std::make_shared<Node>();
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
