#include "node.h"
#include "util/ptr.h"

namespace fluster { namespace ast {


//// Construction

Node::
Node()
    : outer(WeakPtr<Node>())
{}

Node::
Node(Node::Ptr in_outer)
    : outer(in_outer)
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
