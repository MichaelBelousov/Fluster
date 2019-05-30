#ifndef FLUSTER_COMPILER_AST_COMMA_DELIMITED_LIST
#define FLUSTER_COMPILER_AST_COMMA_DELIMITED_LIST

#include <vector>
#include <memory>
#include "node.h"

namespace fluster { namespace ast {



struct CommaDelimitedList final
    : public Node
{
    //// Methods
    void
    append(Node::Ptr in);

    //// Construction
    static
    Block::Ptr
    empty();

    static
    CommaDelimitedList::Ptr
    fromFirst(Node::Ptr first);

    //// Types
    using Ptr = std::shared_ptr<CommaDelimitedList>;

private:

    //// Members
    std::vector<Node::Ptr> elements;
};



} }

#endif //FLUSTER_COMPILER_AST_COMMA_DELIMITED_LIST
