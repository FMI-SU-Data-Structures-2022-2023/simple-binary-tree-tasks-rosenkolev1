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

bool nodesAreSymmetric(Node* leftNode, Node* rightNode) {
    if (leftNode == nullptr && rightNode != nullptr ||
            rightNode == nullptr && leftNode != nullptr) {
        return false;
    }
    else if(leftNode == nullptr && rightNode == nullptr)
        return true;

    if(leftNode->key == rightNode->key) {
        return nodesAreSymmetric(leftNode->left, rightNode->right) &&
                nodesAreSymmetric(leftNode->right, rightNode->left);
    }

    return false;

}

bool isSymmetric(Node* tree) {
    if(tree == nullptr)
        return true;

    return nodesAreSymmetric(tree->left, tree->right);
}

bool isSubtreeBST(Node* tree, Node* parentNode, bool greaterThanParent) {

    bool leftIsLesser = true;
    bool rightIsGreater = true;

    if(tree == nullptr)
        return true;

    if(tree->left != nullptr) {
        leftIsLesser = tree->left->key < tree->key;

        if(parentNode != nullptr) {
            if(!greaterThanParent){
                leftIsLesser =  leftIsLesser && tree->left->key < parentNode->key;
            }
            else {
                leftIsLesser = leftIsLesser && tree->left->key > parentNode->key;
            }
        }
    }
    if(tree->right != nullptr) {
        rightIsGreater = tree->right->key > tree->key;

        if(parentNode != nullptr) {
            if(!greaterThanParent){
                rightIsGreater =  rightIsGreater && tree->right->key < parentNode->key;
            }
            else {
                rightIsGreater = rightIsGreater && tree->right->key > parentNode->key;
            }
        }
    }

    return leftIsLesser && rightIsGreater &&
            isSubtreeBST(tree->left, tree, false) &&
            isSubtreeBST(tree->right, tree, true);
}

bool isBST(Node* tree) {
    return isSubtreeBST(tree, nullptr, false);
}

std::string getInorder(Node* tree) {

    std::string endRes = "";

    if(tree == nullptr)
        return "";

    endRes += getInorder(tree->left);
    endRes += std::to_string(tree->key) + ", ";
    endRes += getInorder(tree->right);

    return endRes;
}

std::string getPreorder(Node* tree) {
    std::string endRes = "";

    if(tree == nullptr)
        return "";

    endRes += std::to_string(tree->key) + ", ";
    endRes += getPreorder(tree->left);
    endRes += getPreorder(tree->right);

    return endRes;
}

std::string getPostorder(Node* tree) {
    std::string endRes = "";

    if(tree == nullptr)
        return "";

    endRes += getPostorder(tree->left);
    endRes += getPostorder(tree->right);
    endRes += std::to_string(tree->key) + ", ";

    return endRes;
}