Here is the code:

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};

Node* createNode(int key) {
    Node* newNode = new Node;
    newNode->key = key;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insertNode(Node* root, int key) {
    if (root == nullptr) {
        root = createNode(key);
    } else {
        if (key < root->key) {
            root->left = insertNode(root->left, key);
        } else if (key > root->key) {
            root->right = insertNode(root->right, key);
        }
    }
    return root;
}

int findLargestKeySmallerThanX(Node* root, int x) {
    if (root == nullptr) {
        return -1;
    } else if (root->key < x) {
        return findLargestKeySmallerThanX(root->right, x);
    } else {
        int leftAns = findLargestKeySmallerThanX(root->left, x);
        return (leftAns == -1) ? root->key : leftAns;
    }
}

int main() {
    int N, x;
    cin >> N;
    Node* root = nullptr;
    while (N--) {
        int key;
        cin >> key;
        root = insertNode(root, key);
    }
    cin >> x;
    cout << findLargestKeySmallerThanX(root, x) << endl;
    return 0;
}

This program first reads the number N, then for each key, it inserts the key into the Binary Search Tree. After that, it reads the value X. It then finds the largest key smaller than X from the BST and prints it.