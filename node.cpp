#include <iostream>
#include "node.h"

// constructors
Node::Node(std::string v, int c) {
    value = v;
    count = c;
    left = NULL;
    right = NULL;
    parent = NULL;
}

Node::Node(std::string v, int c, Node l, Node r, Node p) {
    value = v;
    count = c;
    left = &l;
    right = &r;
    parent = &p;
}

Node::Node(Node* l, Node* r) {
  value = l->value + "_" + r->value;
  count = l->count + r->count;
  left = l;
  right = r;
  left->parent = this;
  right->parent = this;
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
int Node::get_count() {
    return count;
}

std::string Node::get_value() {
    return value;
}

// operators

bool Node::operator<(Node &rhs) {
  return count < rhs.count;
}
