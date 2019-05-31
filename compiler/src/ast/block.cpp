#include "block.h"

namespace fluster { namespace ast {



void
Block::
append(Node::Ptr in)
{
    lines.emplace_back(in);  //std::move
}


Block::Ptr
Block::
empty()
{
    return Block::Ptr();
}



} }
