Here is the code for the problem:

#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};

Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = node->right = NULL;
    return(node);
}

Node* insert(Node* node, int key) {
    if (node == NULL)
        return(newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    return(node);
}

int findFloor(Node* node, int key) {
    if (node == NULL)
        return -1;

    if (node->key == key)
        return node->key;

    if (node->key < key)
        return findFloor(node->right, key);

    if (node->left == NULL)
        return (node->key - 1);

    return findFloor(node->left, key);
}

int main() {
    Node* root = NULL;

    int keys[] = { 20, 8, 22, 4, 12, 10, 14 };
    int n = sizeof(keys) / sizeof(keys[0]), i;

    for (i = 0; i < n; i++)
        root = insert(root, keys[i]);

    int key = 16;
    cout << "Floor of " << key << " in the BST is: "
        << findFloor(root, key) << endl;

    return 0;
}

In this code, the structure of the Node is defined to hold the key, left and right children. The `newNode` function creates a new node with a given key. The `insert` function inserts a new key into the tree. The `findFloor` function finds the largest key in the tree that is less than or equal to a given key.