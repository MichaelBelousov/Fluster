#include <iostream>
#include "util/ptrs.h"
#include "node.h"

namespace fluster { namespace ast {


//// Construction

Node::
Node(Node::Ptr in_outer)
    : outer(in_outer)
{}

//// Methods

void
Node::
print(std::ostream& os, unsigned indent_level) const
{
    for (unsigned i = 0; i < indent_level; ++i) os << " ";
    os << "<NODE/>" << std::endl;
}

Node::Ptr
Node::
makeRootNode()
{
    auto new_root = Node::Ptr();
    return new_root
}

//// Operators

std::ostream& 
operator<<(std::ostream& os, const Node& node)
{
    node.print(os, 0);
    return os;
}



} }
