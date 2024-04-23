//
// Created by andrei on 4/3/23.
//

#ifndef LAB7_2_TREE_H
#define LAB7_2_TREE_H

#include <iostream>
#include <vector>

template <typename T>
class Tree {
private:



public:

    struct Node {
        T value;
        std::vector<Node*> children;
        Node* parent;
        Node(const T& v) : value(v), parent(nullptr) {}
        ~Node() {
            for (Node* child : children) {
                delete child;
            }
        }
    };
    Node* root;



    Tree() : root(nullptr) {}
    ~Tree() {
        delete root;
    }

    void add_node(Node* parent, Node* node);

    Node* get_node(Node* parent = nullptr) const;

    void delete_node(Node* parent, Node* node);

    Node* find(Node* node, bool (*cmp)(const T&)) const;

    void insert(Node* parent, Node* node, int index);

    void sort(Node* node, bool (*cmp)(const T&, const T&) = nullptr);

    int count(Node* node = nullptr) const;

};


#endif //LAB7_2_TREE_H
