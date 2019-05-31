#ifndef FLUSTER_COMPILER_AST_NODE
#define FLUSTER_COMPILER_AST_NODE

#include <iostream>
#include "util/ptrs.h"
#include "data/construct.h"

namespace fluster { namespace ast {



struct Node
    : public std::enable_shared_from_this<Node>
{
    //// Types
    using Ptr = util::Ptr<Node>;

    //// Methods
    friend std::ostream& operator<<(std::ostream& os, const Node& node);

    //virtual const data::Construct::Ptr finalize() const = 0;

    // TODO: make protected
    virtual void print(std::ostream& os, unsigned indent_level) const;

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

    virtual ~Node();

    //// Members
    const util::WeakPtr<Node> outer;
};



} }

#include "node.tpp"

#endif //FLUSTER_COMPILER_AST_NODE
