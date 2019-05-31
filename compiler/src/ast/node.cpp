#include "node.h"
#include "util/ptrs.h"

namespace fluster { namespace ast {


//// Construction

Node::
Node()
    : outer(util::WeakPtr<Node>::null())
{}

Node::
Node(Node::Ptr in_outer)
    : outer(util::WeakPtr<Node>::copy(in_outer))
{}

//// Methods

Node::Ptr
Node::
makeRootNode()
{
    // TODO: have custom function for making Node::Ptr's
    return Node::Ptr();
}



} }
