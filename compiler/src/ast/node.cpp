#include "node.h"
#include "util/ptrs.h"

namespace fluster { namespace ast {


//// Construction

Node::
Node()
    : outer()
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
    return Node::Ptr();
}



} }
