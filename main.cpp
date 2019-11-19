#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>

#include "node.h"
#include "tree.h"


bool compare_pairs_decreasing(
  std::pair<std::string, int> &a,
  std::pair<std::string, int> &b
) {
    return a.second < b.second;
}

std::vector<Node*> initialize_node_queue(
    std::map<std::string, int> &char_count_dict
) {
    std::vector<std::pair<std::string, int>> elems(
      char_count_dict.begin(), char_count_dict.end()
    );
    sort(elems.begin(), elems.end(), compare_pairs_decreasing);

    std::vector<Node*> node_queue;
    for (auto e: elems) {
        Node* n = new Node(e.first, e.second);
        node_queue.push_back(n);
    }

    return node_queue;
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

Tree build_tree(std::vector<Node*>& leaf_q) {
    while (leaf_q.size() > 1) {
        Node* n1 = new Node(leaf_q.at(0), leaf_q.at(1));
        leaf_q.erase(leaf_q.begin(), leaf_q.begin() + 2);

        size_t i;
        for (i = 0; i < leaf_q.size(); i++ ) {
            if (n1->get_count() < leaf_q.at(i)->get_count()) {
                break;
            }
        }
        leaf_q.insert(leaf_q.begin() + i, n1);
    }

    return Tree(leaf_q.at(0));
}


int main(int argc, char** argv) {

    std::ifstream input_file (argv[1]);

    if (input_file.is_open()) {} else {
        std::cout << "Cannot open file: " << argv[1] << "\n";
        return 1;
    }

    auto huffmap = build_huffman_dict(input_file);
    // file no longer needed
    input_file.close();

    auto nq = initialize_node_queue(huffmap);
    auto tree = build_tree(nq);

    tree.get_root_node()->print_nodes_with_order(2);

    int counter = 0;
    for (auto n: nq) {
        counter += n->get_count();
    }

    printf("Total chars = %d\n", counter);
    
    return 0;
}
