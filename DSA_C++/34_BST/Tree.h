#ifndef TREENODE_H
#define TREENODE_H

class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

#endif // TREENODE_H