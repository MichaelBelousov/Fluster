#ifndef FLUSTER_COMPILER_AST_BLOCK
#define FLUSTER_COMPILER_AST_BLOCK

#include <vector>
#include <memory>
#include "node.h"

namespace fluster { namespace ast {



struct Block final
    : public Node
{
    //// Methods

    void
    append(Node::Ptr in);

    //// Construction

    Block() = default;

    static
    Block::Ptr
    empty();

    //// Types

    using Ptr = std::shared_ptr<Block>;

private:

    //// Members

    std::vector<Node::Ptr> lines;

};



}; };

#endif //FLUSTER_COMPILER_AST_BLOCK
