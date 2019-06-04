#ifndef FLUSTER_COMPILER_AST_NODE
#define FLUSTER_COMPILER_AST_NODE

#include <iostream>
#include <memory>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Value.h>
#include "db/program_database.h"
#include "util/ptrs.h"

/*
 * Compilation process:
 * - lexer -> feeds tokens to parser -> builds AST nodes recursively bottom-up
 * - starting from Root, nodes commit their forms into the database
 * - finally, nodes generate code with the finalized program (global scope db) database
 */

namespace fluster { namespace ast {



// forward declarations
struct GenerationContext;



struct Node
    : public std::enable_shared_from_this<Node>
{
    //// Types
    using Ptr = util::Ptr<Node>;

    //// Methods
    virtual void commit(db::ProgramDatabase& db) const = 0;  //commit contents to db

    virtual llvm::Value* generateCode(GenerationContext& ctx) const = 0;

    virtual void print(std::ostream& os, unsigned indent_level) const;

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
