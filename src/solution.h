#ifndef WEEK6_TREE_H
#include <iostream>

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int _key) : key(_key), left(nullptr), right(nullptr) {}
};

int countElements(Node*);
int countLeafs(Node*);
int sumElements(Node*);
int sumElementsAtLevel(Node*, unsigned);
int height(Node*);
bool isBST(Node*);
bool isSymmetric(Node*);
std::string getInorder(Node* tree);
std::string getPreorder(Node* tree);
std::string getPostorder(Node* tree);

#define WEEK6_TREE_H

#endif //WEEK6_TREE_H
