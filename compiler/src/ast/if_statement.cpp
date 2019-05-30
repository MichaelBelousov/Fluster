#include <memory>
#include "if_statement.h"

namespace fluster { namespace ast {

//// Methods

static
IfStatement::Ptr
IfStatement::
empty()
{
    return make_shared<IfStatement>();
}

//// Construction

IfStatement::
IfStatement( Expr::Ptr in_cond
           , Node::Ptr in_then
           , Node::Ptr in_else = empty()
           )
    : cond(in_cond)
    , then(in_then)
    , else_(in_else)
{}



} }

#endif //FLUSTER_COMPILER_AST_IF_STATEMENT
