#ifndef FLUSTER_COMPILER_AST_NODE
#define FLUSTER_COMPILER_AST_NODE

#include <iostream>
#include <memory>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Value.h>
#include "db/program_database.h"
#include "util/ptrs.h"

namespace fluster { namespace ast {



// forward declerations
struct GenerationContext;



struct Node
    : public std::enable_shared_from_this<Node>
{
    //// Types
    using Ptr = util::Ptr<Node>;

    //// Methods
    virtual llvm::Value* generateCode(GenerationContext& ctx) const = 0;

    // TODO: hide from non descendents protected
    virtual void print(std::ostream& os, unsigned indent_level) const;
    // emit the new type to the program database
    //virtual void submitConstruct(db::ProgramDatabase& db) const = 0;

    template<typename T, typename ...Args>
    Node::Ptr makeChildNode(Args&& ...args); 

    template<typename T, typename ...Args>
    Node::Ptr makeParentNode(Args&& ...args); 

    static Node::Ptr makeRootNode();

    //// Operators
    friend std::ostream& operator<<(std::ostream& os, const Node& node);

    //// Construction
    // TODO: make it so only makeParentNode can be used to construct
    // new nodes, via a private constructor
//private:
    Node(Node::Ptr outer);
    Node() = default;
    virtual ~Node() = default;

protected:

    const util::WeakPtr<Node> outer;
};



} }

#include "node.tpp"

#endif //FLUSTER_COMPILER_AST_NODE
