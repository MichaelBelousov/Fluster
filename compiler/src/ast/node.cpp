#include "node.h"
#include <memory>

namespace fluster { namespace ast {



//// Construction

Node::
Node()
    : outer(std::weak_ptr<Node>())
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
    return std::make_shared<Node>();
}



} }
