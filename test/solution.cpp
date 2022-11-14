#include "catch2/catch_all.hpp"
#include "solution.h"

void clean(Node*& n) {
    if (n == nullptr) return;
    clean(n->left);
    clean(n->right);
    delete n;
}

TEST_CASE("Validate countElements") {
    Node* test = new Node(5);
    test->left = new Node(7);
    test->right = new Node(7);
    test->left->left = new Node(14);

    CHECK(countElements(nullptr) == 0);
    CHECK(countElements(test) == 4);
    test->left->left->right = new Node(18);
    CHECK(countElements(test) == 5);
    clean(test);
}


TEST_CASE("Validate countLeafs") {
    Node* test = new Node(5);
    test->left = new Node(7);
    test->right = new Node(7);
    test->left->left = new Node(14);
    CHECK(countLeafs(nullptr) == 0);
    CHECK(countLeafs(test) == 2);
    test->left->left->right = new Node(18);
    test->left->left->left = new Node(20);
    CHECK(countLeafs(test) == 3);
    clean(test);
}

TEST_CASE("Validate height") {
    CHECK(height(nullptr) == 0);
    Node* test = new Node(5);
    CHECK(height(test) == 1);
    test->left = new Node(7);
    test->right = new Node(7);
    test->left->left = new Node(14);
    test->left->left->right = new Node(18);
    CHECK(height(test) == 4);
    clean(test);
}

TEST_CASE("Validate sumElements") {
    CHECK(sumElements(nullptr) == 0);
    Node* test = new Node(5);
    CHECK(sumElements(test) == 5);
    test->left = new Node(6);
    test->right = new Node(1);
    test->left->left = new Node(2);
    test->left->left->right = new Node(3);
    CHECK(sumElements(test) == 17);
    clean(test);
}

TEST_CASE("Validate sumElementsAtLevel") {
    CHECK(sumElementsAtLevel(nullptr, 0) == 0);
    Node* test = new Node(5);
    CHECK(sumElementsAtLevel(test,0) == 5);
    test->left = new Node(6);
    test->right = new Node(1);
    test->left->left = new Node(2);
    test->left->left->right = new Node(3);
    CHECK(sumElementsAtLevel(test, 0) == 5);
    CHECK(sumElementsAtLevel(test, 1) == 7);
    CHECK(sumElementsAtLevel(test, 2) == 2);
    CHECK(sumElementsAtLevel(test, 3) == 3);

    clean(test);

}

TEST_CASE("Validate isSymmetric") {
    Node* test = new Node(5);
    CHECK(isSymmetric(test) == true);

    test->left = new Node(6);
    test->right = new Node(1);
    CHECK(isSymmetric(test) == false);

    test->left->key = 1;
    CHECK(isSymmetric(test) == true);

    test->left->left = new Node(2);
    test->right->right = new Node(2);
    CHECK(isSymmetric(test) == true);

    test->right->right = new Node(3);
    CHECK(isSymmetric(test) == false);
    clean(test);
}

TEST_CASE("Validate isBST") {

    Node* test = new Node(5);
    CHECK(isBST(test) == true);

    test->left = new Node(0);
    CHECK(isBST(test) == true);

    test->left->key = 12;
    CHECK(isBST(test) == false);

    test->left->key = 0;
    test->right = new Node(10);
    CHECK(isBST(test) == true);

    test->right->right = new Node(20);
    CHECK(isBST(test) == true);

    test->right->left = new Node(30);
    CHECK(isBST(test) == false);

    clean(test);
}

TEST_CASE("Validate print inorder") {

    CHECK(getInorder(nullptr) == "");

    Node* test = new Node(5);
    CHECK(getInorder(test) == "5, ");

    test->left = new Node(10);
    test->left->left = new Node(3);
    test->left->right = new Node(6);
    test->right = new Node(7);
    test->right->left = new Node(14);
    test->right->right = new Node(-4);

    std::string expectedResult = "3, 10, 6, 5, 14, 7, -4, ";
    CHECK(getInorder(test) == expectedResult);

    clean(test);
}

TEST_CASE("Validate print preorder") {

    CHECK(getPreorder(nullptr) == "");

    Node* test = new Node(5);
    CHECK(getPreorder(test) == "5, ");

    test->left = new Node(10);
    test->left->left = new Node(3);
    test->left->right = new Node(6);
    test->right = new Node(7);
    test->right->left = new Node(14);
    test->right->right = new Node(-4);

    std::string expectedResult = "5, 10, 3, 6, 7, 14, -4, ";
    CHECK(getPreorder(test) == expectedResult);

    clean(test);
}

TEST_CASE("Validate print postorder") {

    CHECK(getPostorder(nullptr) == "");

    Node* test = new Node(5);
    CHECK(getPostorder(test) == "5, ");

    test->left = new Node(10);
    test->left->left = new Node(3);
    test->left->right = new Node(6);
    test->right = new Node(7);
    test->right->left = new Node(14);
    test->right->right = new Node(-4);

    std::string expectedResult = "3, 6, 10, 14, -4, 7, 5, ";
    CHECK(getPostorder(test) == expectedResult);

    clean(test);
}