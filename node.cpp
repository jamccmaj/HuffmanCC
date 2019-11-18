#include "node.h"

// constructors
Node::Node(std::string v, int d) {
    value = v;
    data = d;
    left = NULL;
    right = NULL;
    parent = NULL;
}

Node::Node(std::string v, int d, Node l, Node r, Node p) {
    value = v;
    data = d;
    left = &l;
    right = &r;
    parent = &p;
}

// role accessors
bool Node::is_leaf() {
  return !left && !right;
}

bool Node::is_root() {
  return !parent;
}

bool Node::is_internal() {
    return !is_leaf() && !is_root();
}

// data accessors
int Node::get_data() {
    return data;
}

std::string Node::get_value() {
    return value;
}

// operators

bool Node::operator<(Node &rhs) {
  return data < rhs.data;
}
