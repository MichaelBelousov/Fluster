#include "block.h"

namespace fluster { namespace ast {



void
Block::
append(Node::Ptr in)
{
    lines.emplace_back(std::move(in));
}


static
Block::Ptr
Block::
empty()
{
    return Block::Ptr(new Block());
}



}; };
