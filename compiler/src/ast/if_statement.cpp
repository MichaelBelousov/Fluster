#include <memory>
#include "if_statement.h"

namespace fluster { namespace ast {

//// Methods
static
IfStatement::Ptr
empty()
{
    return make_shared<IfStatement>();
}

//// Construction

IfStatement( Expr::Ptr in_cond
           , Block::Ptr in_then
           , Block::Ptr in_else = Block::empty()
           )
    : cond(in_cond)
    , then(in_then)
    , else_(in_else)
{}



}; };

#endif //FLUSTER_COMPILER_AST_IF_STATEMENT
