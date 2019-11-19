#include "tree.h"

Tree::Tree(Node* n) {
    root = n;
}

Node* Tree::get_root_node() {
	return root;
}
