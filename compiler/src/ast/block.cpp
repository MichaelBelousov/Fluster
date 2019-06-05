#include "block.h"
#include <llvm/IR/BasicBlock.h>
#include "context.h"

namespace fluster { namespace ast {


//// Methods

void
Block::
commit(db::ProgramDatabase& db) const
{
    for (const auto& line : lines)
        line->commit(db);
}

llvm::Value*
Block::
generateCode(GenerationContext& ctx) const
{
    auto owner = ctx.builder.GetInsertBlock()->getParent();
    auto block = llvm::BasicBlock::Create(
        ctx.context,
        "block",
        owner
    );
    ctx.builder.SetInsertPoint(block);
    for (const auto& line : lines)
        line->generateCode(ctx);
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

void
Block::
append(Node::Ptr in)
{
    lines.emplace_back(in);  //XXX: std::move
}

//// Class Functions

Block::Ptr
Block::
empty()
{
    return Block::Ptr();
}



} }
