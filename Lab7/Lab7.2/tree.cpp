#include "tree.h"
#include <vector>
#include <algorithm>


template <typename T>
void Tree<T>::add_node(Node* parent, Node* node) {
    if (parent == nullptr) {
        if (root == nullptr) {
            root = node;
        } else {
            delete node;
            std::cerr << "Error: root already exists.\n";
        }
    } else {
        parent->children.push_back(node);
        node->parent = parent;
    }
}

template <typename T>
typename Tree<T>::Node* Tree<T>::get_node(Node* parent) const {
    if (parent == nullptr) {
        return root;
    } else {
        return parent;
    }
}

template <typename T>
void Tree<T>::delete_node(Node* parent, Node* node) {
    typename std::vector<Node*>::iterator it = std::find(parent->children.begin(), parent->children.end(), node);
    if (it != parent->children.end()) {
        parent->children.erase(it);
        delete node;
    }
}

template <typename T>
typename Tree<T>::Node* Tree<T>::find(Node* node, bool (*cmp)(const T&)) const {
    if (node == nullptr) {
        return nullptr;
    }

    if (cmp(node->value)) {
        return node;
    }

    for (Node* child : node->children) {
        Node* result = find(child, cmp);
        if (result != nullptr) {
            return result;
        }
    }

    return nullptr;
}



template <typename T>
void Tree<T>::insert(Node* parent, Node* node, int index) {
    if (index < 0 || index > static_cast<int>(parent->children.size())) {
        delete node;
        std::cerr << "Error: index out of range.\n";
        return;
    }
    parent->children.insert(parent->children.begin() + index, node);
    node->parent = parent;
}




template <typename T>
int Tree<T>::count(Node* node) const {
    if (node == nullptr) {
        node = root; // Start counting from the root node
    }

    int cnt = 0;
    if (node != nullptr) {
        cnt = 1; // Count the current node
        for (Node* child : node->children) {
            cnt += count(child); // Recursively count nodes in children
        }
    }
    return cnt;
}

template <typename T>
void Tree<T>::sort(Node* node, bool (*cmp)(const T&, const T&) /*= nullptr*/) {
    if (node == nullptr) {
        return;
    }

    // If no comparator function is provided, use the less than operator
    if (cmp == nullptr) {
        std::sort(node->children.begin(), node->children.end(),
                  [](const Node* a, const Node* b) { return a->value < b->value; });
    } else {
        std::sort(node->children.begin(), node->children.end(),
                  [cmp](const Node* a, const Node* b) { return cmp(a->value, b->value); });
    }

    // Recursively sort children nodes
    for (Node* child : node->children) {
        sort(child, cmp);
    }
}





