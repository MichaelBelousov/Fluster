#ifndef FLUSTER_COMPILER_AST_COMMA_DELIMITED_LIST
#define FLUSTER_COMPILER_AST_COMMA_DELIMITED_LIST

#include <vector>
#include "util/ptrs.h"
#include "node.h"
#include "block.h"

namespace fluster { namespace ast {


//NOTE: need a *frozen* object for each ast node, no?

struct CommaDelimitedList final
    : public Node
{
    //// Types
    using Ptr = util::Ptr<CommaDelimitedList>;

    //// Methods
    void
    append(Node::Ptr in);

    //// Construction
    static
    Node::Ptr
    empty();

    static
    CommaDelimitedList::Ptr
    fromFirst(Node::Ptr first);

private:
    //// Members
    std::vector<Node::Ptr> elements;
};



} }

#endif //FLUSTER_COMPILER_AST_COMMA_DELIMITED_LIST
