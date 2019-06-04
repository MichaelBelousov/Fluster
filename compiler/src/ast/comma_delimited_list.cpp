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

std::vector<Node::Ptr>::iterator
CommaDelimitedList::
begin()
{
    return elements.begin();
}

std::vector<Node::Ptr>::iterator
CommaDelimitedList::
end()
{
    return elements.end();
}

//// Construction

Node::Ptr
CommaDelimitedList::
empty()
{
    return CommaDelimitedList::Ptr().castUp<Node>();
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
