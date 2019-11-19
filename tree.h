#ifndef TREE_H
#define TREE_H

#include "node.h"

class Tree {
    Node* root;

    public:
        // constructors
        Tree(Node*);
        Node* get_root_node();
};

#endif
