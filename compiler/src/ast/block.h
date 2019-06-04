#ifndef FLUSTER_COMPILER_AST_BLOCK
#define FLUSTER_COMPILER_AST_BLOCK

#include <vector>
#include "util/ptrs.h"
#include "node.h"

namespace fluster { namespace ast {



struct Block final
    : public Node
{
    //// Types
    using Ptr = util::Ptr<Block>;

    //// Overidden Methods
    void commit(db::ProgramDatabase& db) const override;
    llvm::Value* generateCode(GenerationContext& ctx) const override;
    void print(std::ostream& os, unsigned indent_level) const override;

    //// Methods
    void append(Node::Ptr in);

    //// Static functions
    static
    Block::Ptr
    empty();

    //// Construction
    //Block() = default;

private:
    //// Members
    std::vector<Node::Ptr> lines;
};



} }

#endif //FLUSTER_COMPILER_AST_BLOCK
