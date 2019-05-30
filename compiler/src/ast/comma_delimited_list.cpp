#include <vector>
#include "comma_delimited_list.h"

namespace fluster { namespace ast {



//// Methods

void
CommaDelimitedList::
append(Node::Ptr in)
{
    elements.emplace_back(in);
}

//// Construction

Node::Ptr
CommaDelimitedList::
empty()
{
    return CommaDelimitedList::Ptr().CastUp<Node>();
}

CommaDelimitedList::Ptr
CommaDelimitedList::
fromFirst(Node::Ptr first)
{
    auto result = CommaDelimitedList::Ptr();
    result->elements.emplace_back(first);
    return result;
}



} }
