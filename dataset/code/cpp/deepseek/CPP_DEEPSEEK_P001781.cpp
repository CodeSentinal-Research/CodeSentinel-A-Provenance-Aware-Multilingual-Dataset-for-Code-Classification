Here is the C++ code for the given problem.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int countSymmetricSubtrees(Node* root, int &res) {
    if (root == NULL)
        return 0;

    int left = countSymmetricSubtrees(root->left, res);
    int right = countSymmetricSubtrees(root->right, res);

    int subtree = max(max(left, right) + 1, 0);
    if (subtree == left && subtree == right)
        res++;

    return subtree;
}

int countSymmetricSubTrees(Node* root) {
    int res = 0;
    countSymmetricSubtrees(root, res);
    return res;
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
    root->right->right->left = newNode(7);
    root->right->right->right = newNode(8);

    cout << "Number of Symmetric SubTrees: " << countSymmetricSubTrees(root) << endl;

    return 0;
}

This code first creates a binary tree from the given input and then counts the number of symmetric subtrees in it.