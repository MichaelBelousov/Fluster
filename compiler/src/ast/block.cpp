#include "block.h"

namespace fluster { namespace ast {



void
Block::
append(Node::Ptr in)
{
    //std::move
    lines.emplace_back(in);
}


Block::Ptr
Block::
empty()
{
    return Block::Ptr(new Block());
}



} }
