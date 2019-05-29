#include "node.h"
#include "util.h"
#include <memory>

namespace fluster { namespace ast {



//// Construction

Node::
Node(Node::Ptr in_outer)
    : outer(in_outer)
{

}

//// Methods

Node::Ptr
Node::
makeRoot()
{
    return Node::Ptr(std::weak_ptr<Node>());
}



}; };

#endif //FLUSTER_COMPILER_AST_BASE
