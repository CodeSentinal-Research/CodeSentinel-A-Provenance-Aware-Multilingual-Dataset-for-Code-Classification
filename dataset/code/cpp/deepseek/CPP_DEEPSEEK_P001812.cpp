Here is the C++ code for the problem:

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

struct Node {
    int key;
    Node *left, *right;
};

Node* createNode(int key) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory error" << endl;
        return NULL;
    }
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int key) {
    if (root == NULL) {
        root = createNode(key);
    } else if (key < root->key) {
        root->left = insertNode(root->left, key);
    } else {
        root->right = insertNode(root->right, key);
    }
    return root;
}

void printRange(Node* root, int l, int r) {
    if (!root)
        return;

    if (root->key > l)
        printRange(root->left, l, r);

    if (l <= root->key && root->key <= r)
        cout << root->key << " ";

    if (root->key < r)
        printRange(root->right, l, r);
}

int main() {
    Node* root = NULL;
    int n, key, l, r;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> key;
        root = insertNode(root, key);
    }
    cin >> l >> r;
    printRange(root, l, r);

    return 0;
}

This code first creates a binary search tree from the input, then it prints all keys within the range [L, R]. The `printRange` function is a recursive function that traverses the tree in a pre-order manner and prints the keys within the given range.