Here is a C++ solution for the problem. This solution uses the concept of Binary Search Tree (BST) and the property of BST that in a BST, for any node, all the nodes in its left subtree are less than it, and all the nodes in its right subtree are greater than it.

#include <iostream>
using namespace std;

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* insert(struct Node* node, int key) {
    if (node == NULL) return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

struct Node* LCA(struct Node* node, int n1, int n2) {
    if (node->key > n1 && node->key > n2)
        return LCA(node->left, n1, n2);

    if (node->key < n1 && node->key < n2)
        return LCA(node->right, n1, n2);

    return node;
}

int main() {
    struct Node *root = NULL;
    int n, key1, key2;
    cin >> n;
    int data;
    for(int i = 0; i < n; i++) {
        cin >> data;
        root = insert(root, data);
    }
    cin >> key1 >> key2;
    struct Node* lca = LCA(root, key1, key2);
    cout << lca->key;
    return 0;
}
In this code, we first create a new node and insert it into the BST. Then, we find the Lowest Common Ancestor of two given keys. The function `LCA()` finds the LCA of two given keys by comparing them recursively.