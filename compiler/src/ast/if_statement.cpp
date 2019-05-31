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

//// Construction

// NOTE: the current ptr design makes it difficult to construct empty pointers
// in initializer lists and other contexts, this work around is ok
// The real issue is the lack of basic copy and move construction of the pointer
// itself. Maybe make the private constructor un-private and usable? I prefer this
// forced no-initializer usage for a cleaner interface
IfStatement::
IfStatement()
    : cond()
    , then()
    , else_()
{
}

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
