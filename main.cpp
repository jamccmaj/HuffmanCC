#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Node {
    int data;
    string value;

    Node * left;
    Node * right;
    Node * parent;

    public:
        // constructors
        Node(string, int);
        Node(string, int, Node, Node, Node);

        // role in tree
        bool is_leaf();
        bool is_root();
        bool is_internal();

        // data access
        int get_data();
        string get_value();

};

// constructors
Node::Node(string v, int d) {
    value = v;
    data = d;
    left = NULL;
    right = NULL;
    parent = NULL;
}

Node::Node(string v, int d, Node l, Node r, Node p) {
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

string Node::get_value() {
    return value;
}

bool compare_pairs_decreasing(pair<string, int>& a, pair<string, int>& b) {
    return a.second < b.second;
}

void show_ordered_pairs(map<string, int>& text_table) {
    vector<pair<string, int>> elems(text_table.begin(), text_table.end());
    sort(elems.begin(), elems.end(), compare_pairs_decreasing);
    for (auto e: elems) {
        cout << e.first << " " << e.second << "\n";
    }
 }

map<string, int> build_huffman_dict(ifstream& text) {
    map<string, int> huffmap;
    char c;

    while (text.get(c)) {
        string temp(1, c);
        auto key = huffmap.find(temp);

        if (key != huffmap.end()) {
            huffmap[temp] += 1;
        } else {
            huffmap[temp] = 1;
        }
    }

    return huffmap;
}

int main(int argc, char** argv) {

    ifstream input_file (argv[1]);

    if (input_file.is_open()) {
        auto huffmap = build_huffman_dict(input_file);
        show_ordered_pairs(huffmap);
    } else {
        cout << "Cannot open file: " << argv[1] << "\n";
    }

    cout << "\nTesting node class: \n";

    string s = "A";
    int count = 10;
    Node n = Node(s, count);

    cout << "Value: " << n.get_value() << endl;
    cout << "Count: " << n.get_data() << endl;
    cout << "Is leaf? " << n.is_leaf() << endl;
    cout << "Is root? " << n.is_root() << endl;
    cout << "Is internal? " << n.is_internal() << endl;

    
    return 0;
}
