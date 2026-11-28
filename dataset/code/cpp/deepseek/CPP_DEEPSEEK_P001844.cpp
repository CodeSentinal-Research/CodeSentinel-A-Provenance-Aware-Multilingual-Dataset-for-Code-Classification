Sure, here is the C++ code for finding the largest complete binary search tree subtree:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    int height;
    Node* left;
    Node* right;
    Node(int data) : data(data), height(1), left(NULL), right(NULL) {}
};

class BST {
public:
    Node* root;

    BST() : root(NULL) {}

    int height(Node* node) {
        if (node == NULL)
            return 0;
        return node->height;
    }

    int max(int a, int b) {
        return (a > b) ? a : b;
    }

    Node* newNode(int data) {
        Node* node = new Node(data);
        return node;
    }

    Node* insert(Node* node, int data) {
        if (node == NULL)
            return newNode(data);
        if (data < node->data)
            node->left = insert(node->left, data);
        else if (data > node->data)
            node->right = insert(node->right, data);
        node->height = 1 + max(height(node->left), height(node->right));
        return node;
    }
};

int largestCompleteBSTSubtree(Node* root) {
    if (root == NULL)
        return 0;
    int min = root->data, max = root->data;
    while (root->left != NULL) {
        min = root->left->data;
        root = root->left;
    }
    while (root->right != NULL) {
        max = root->right->data;
        root = root->right;
    }
    return max - min + 1;
}

int main() {
    int N;
    cin >> N;
    BST tree;
    for (int i = 0; i < N; i++) {
        int data;
        cin >> data;
        tree.root = tree.insert(tree.root, data);
    }
    cout << largestCompleteBSTSubtree(tree.root);
    return 0;
}

This code first reads the number of nodes in the tree, then it reads the data of each node. The tree is then inserted into a Binary Search Tree (BST). The largestCompleteBSTSubtree function is then called to find the size of the largest complete BST.