#ifndef FLUSTER_COMPILER_AST_NODE
#define FLUSTER_COMPILER_AST_NODE

/* The fluster data holds immutable, finalized versions
 * of each fluster construct, in a code base, after they
 * have been parsed, and its usage has been semantically validated
 */

#include <memory>
#include "data/construct.h"

namespace fluster { namespace ast {



struct Node
    : public std::enable_shared_from_this<Node>
{
    //// Methods

    // finalize this node, producing its internally consistent construct
    virtual const data::Construct::Ptr finalize() const = 0;

    // make a child of this node
    template<typename T, typename ...Args>
    Node::Ptr makeChild(Args&& ...args); 

    // make an AST root node
    static Node::Ptr makeRoot();

    //// Construction

    Node(Node::Ptr outer);

    //// Types

    using Ptr = std::shared_ptr<Node>;

private:
    //// Members

    const std::weak_ptr<Node> outer;
};

#include "node.tpp"



}; };

#endif //FLUSTER_COMPILER_AST_NODE
