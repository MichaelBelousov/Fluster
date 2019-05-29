#include <memory>
#include "if_statement.h"

namespace fluster { namespace ast {


//// Construction

IfStatement( Expr::Ptr in_cond
           , Block::Ptr in_then
           , Block::Ptr in_else_
           )
    : cond(in_cond)
    , then(in_then)
    , else_(in_else)
{}



}; };

#endif //FLUSTER_COMPILER_AST_IF_STATEMENT
