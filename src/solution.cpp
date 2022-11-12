#include "solution.h"
#include <iostream>

int countElements(Node* tree) {

    int count = 0;
    if (tree == nullptr) return 0;

    count = 1 + countElements(tree->left) + countElements(tree->right);
    return count;

}

int countLeafs(Node* tree) {
    
    if (tree == nullptr) return 0;
    if (tree->left == nullptr && tree->right == nullptr) return 1;
    
    return countLeafs(tree->left) + countLeafs(tree->right);
}

int height(Node* tree) {
    
    if (tree == nullptr) return 0;

    return 1 + (std::max(height(tree->left), height(tree->right)));

}

int sumElements(Node* tree) {
    if (tree == nullptr) return 0;

    return tree->key + sumElements(tree->left) + sumElements(tree->right);
}

int sumElementsAtLevel(Node* tree, unsigned level) {

    if (tree == nullptr) return 0;
    
    if (level == 0)
    {
        return tree->key;
    }

    return sumElementsAtLevel(tree->left, level - 1) + sumElementsAtLevel(tree->right, level - 1);
}

bool isSymmetric(Node* tree) {
    
}

bool isBST(Node* tree) {
    return false;
}