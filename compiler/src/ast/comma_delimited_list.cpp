#include <vector>
#include <memory>
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
    return std::static_pointer_cast<Node>(
        std::make_shared<CommaDelimitedList>()
    );
}

CommaDelimitedList::Ptr
CommaDelimitedList::
fromFirst(Node::Ptr first)
{
    CommaDelimitedList::Ptr result = std::make_shared<CommaDelimitedList>();
    result->elements.emplace_back(first);
    return result;
}



} }
