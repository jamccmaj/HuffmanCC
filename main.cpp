#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>

#include "node.h"
#include "tree.h"


bool compare_pairs_decreasing(std::pair<std::string, int> &a, std::pair<std::string, int> &b) {
    return a.second < b.second;
}

void show_ordered_pairs(std::map<std::string, int> &text_table) {
    std::vector<std::pair<std::string, int>> elems(text_table.begin(), text_table.end());
    sort(elems.begin(), elems.end(), compare_pairs_decreasing);
    for (auto e: elems) {
        std::cout << e.first << " " << e.second << "\n";
    }
 }

std::map<std::string, int> build_huffman_dict(std::ifstream &text) {
    std::map<std::string, int> huffmap;
    char c;

    while (text.get(c)) {
        std::string temp(1, c);
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

    std::ifstream input_file (argv[1]);

    if (input_file.is_open()) {
        auto huffmap = build_huffman_dict(input_file);
        show_ordered_pairs(huffmap);
    } else {
        std::cout << "Cannot open file: " << argv[1] << "\n";
    }

    std::cout << "\nTesting node class: \n";

    std::string s_0 = "A";
    int count_0 = 10;
    Node n = Node(s_0, count_0);

    std::cout << "Value: " << n.get_value() << std::endl;
    std::cout << "Count: " << n.get_data() << std::endl;
    std::cout << "Is leaf? " << n.is_leaf() << std::endl;
    std::cout << "Is root? " << n.is_root() << std::endl;
    std::cout << "Is internal? " << n.is_internal() << std::endl;

    std::string s_1 = "B";
    int count_1 = 15;
    Node* np = new Node(s_1, count_1);
    std::cout << "Value: " << np->get_value() << std::endl;
    std::cout << "Count: " << np->get_data() << std::endl;
    std::cout << "Is leaf? " << np->is_leaf() << std::endl;
    std::cout << "Is root? " << np->is_root() << std::endl;
    std::cout << "Is internal? " << np->is_internal() << std::endl;

    std::cout << (n < *np) << std::endl;
    
    return 0;
}
