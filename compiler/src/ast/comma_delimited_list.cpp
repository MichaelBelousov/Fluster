#include <vector>
#include <memory>
#include "comma_delimited_list.h"

namespace fluster { namespace ast {



//// Methods

void
CommaDelimitedList::
append(Node::Ptr in);

//// Construction

static
Block::Ptr
CommaDelimitedList::
empty()
{
    return CommaDelimitedList();
}

static
CommaDelimitedList::Ptr
CommaDelimitedList::
fromFirst(Node::Ptr first)
{
    auto result = CommaDelimitedList();
    result.emplace_back(first);
    return result;
}



} }
