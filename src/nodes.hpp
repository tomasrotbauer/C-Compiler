#ifndef ECE467_NODE_HPP_INCLUDED
#define ECE467_NODE_HPP_INCLUDED

#include "location.hh"
#include <memory>
#include <vector>

class Node {
public:
    
	yy::location location;
    std::string node_type;
    std::vector<std::unique_ptr<Node>> children;
    
    public:
        Node(std::string node);
    
        friend void grow_tree(Node* root, Node* newNode, std::vector<std::string> claim);
};

#endif // ECE467_NODE_HPP_INCLUDED
