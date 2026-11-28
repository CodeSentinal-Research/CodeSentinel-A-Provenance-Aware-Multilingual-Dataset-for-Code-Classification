#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
};

Node *newNode(int key) {
    Node *node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

Node *insert(Node *node, int key) {
    if (node == NULL) return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}

Node *findPredecessor(Node *root, Node *node) {
    if (node->left != NULL) {
        return max(node->left);
    }
    Node *parent = node;
    node = node->right;
    while (node != NULL) {
        parent = node;
        node = node->left;
    }
    return parent;
}

int main() {
    Node *root = NULL;
    int keys[] = { 20, 10, 40, 30, 50, 70, 60 };
    int n = sizeof(keys) / sizeof(keys[0]);
    for (int i = 0; i < n; i++) {
        root = insert(root, keys[i]);
    }
    int target = 50;
    Node *node = root->left->right; 
    Node *predecessor = findPredecessor(root, node);
    if (predecessor != NULL)
        cout << "Inorder Predecessor of " << node->key << " is " << predecessor->key << endl;
    else
        cout << "Inorder Predecessor of " << node->key << " does not exist" << endl;
    return 0;
}
This C++ code creates a Binary Search Tree and finds the inorder predecessor of a given node. It uses the inorder predecessor as the node that would be the next leftmost node of the target node. If the target node doesn't have a left child, it will print the message "Inorder Predecessor of ..." as well as the predecessor's key.