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

    

int main(int argc, char** argv) {

    std::ifstream input_file (argv[1]);

    if (input_file.is_open()) {} else {
        std::cout << "Cannot open file: " << argv[1] << "\n";
        return 1;
    }

    auto huffmap = build_huffman_dict(input_file);
    auto nq = initialize_node_queue(huffmap);

    int counter = 0;
    for (auto n: nq) {
        std::cout << n->get_value() << " ";
        std::cout << n->get_count() << "\n";
        counter += n->get_count();
    }

    input_file.close();
    printf("Total chars = %d\n", counter);
    
    return 0;
}
