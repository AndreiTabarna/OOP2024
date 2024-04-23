#include "tree.h"
#include "tree.cpp"


bool cmp(const int& a, const int& b) {
    return a > b;
}

int main() {
    Tree<int> my_tree;
    Tree<int>::Node* node1 = new Tree<int>::Node(1);
    Tree<int>::Node* node2 = new Tree<int>::Node(2);
    Tree<int>::Node* node3 = new Tree<int>::Node(3);
    Tree<int>::Node* node4 = new Tree<int>::Node(4);
    Tree<int>::Node* node5 = new Tree<int>::Node(5);

    // add nodes
    my_tree.add_node(nullptr, node1);
    my_tree.add_node(node1, node2);
    my_tree.add_node(node1, node3);
    my_tree.add_node(node2, node4);
    my_tree.add_node(node3, node5);



    // count nodes
    std::cout << "Number of nodes in the tree: " << my_tree.count() << std::endl;

    // find a node starting from the root of the tree
    Tree<int>::Node* found_node = my_tree.find(my_tree.root, [](const int& value) { return value == 3; });
    if (found_node != nullptr) {
        std::cout << "Found node with value 3" << std::endl;
    } else {
        std::cout << "Node with value 3 not found" << std::endl;
    }

    // insert a node
    Tree<int>::Node* node6 = new Tree<int>::Node(6);
    my_tree.insert(node2, node6, 1);


    return 0;
}
