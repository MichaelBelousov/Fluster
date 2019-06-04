#include "block.h"

namespace fluster { namespace ast {



void
Block::
append(Node::Ptr in)
{
    lines.emplace_back(in);  //std::move
}

void
Block::
print(std::ostream& os, unsigned indent_level) const
{
    for (unsigned i = 0; i < indent_level; ++i) os << " ";
    os << "<block>" << std::endl;
    //TODO: make 2 a constant, indenting
    for (const auto& line : lines)
        line->print(os, indent_level+1);
    for (unsigned i = 0; i < indent_level; ++i) os << " ";
    os << "</block>" << std::endl;
}


Block::Ptr
Block::
empty()
{
    return Block::Ptr();
}



} }
