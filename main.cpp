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

    public:
        Node(string, int);
        Node(string, int, Node, Node);

};

Node::Node(string v, int d) {
    value = v;
    data = d;
    left = NULL;
    right = NULL;
}

Node::Node(string v, int d, Node l, Node r) {
    value = v;
    data = d;
    left = &l;
    right = &r;
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
    
    return 0;
}
