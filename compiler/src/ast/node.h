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
    //// Types
    using Ptr = std::shared_ptr<Node>;

    //// Methods
    //virtual const data::Construct::Ptr finalize() const = 0;

    template<typename T, typename ...Args>
    Node::Ptr makeChildNode(Args&& ...args); 

    template<typename T, typename ...Args>
    Node::Ptr makeParentNode(Args&& ...args); 

    static Node::Ptr makeRootNode();

    //// Construction
    Node(Node::Ptr outer);

    // TODO: make it so only makeParentNode can be used to construct
    // new nodes, via the private default constructor
//private:
    Node();

    //// Members
    const std::weak_ptr<Node> outer;
};



} }

#include "node.tpp"

#endif //FLUSTER_COMPILER_AST_NODE
