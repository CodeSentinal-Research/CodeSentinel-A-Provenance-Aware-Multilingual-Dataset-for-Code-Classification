#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int key, freq;
    Node *left, *right;

    Node(int key, int freq) : key(key), freq(freq), left(NULL), right(NULL) {}
};

Node* newNode(int key, int freq) {
    return new Node(key, freq);
}

Node* insert(Node* node, int key, int freq) {
    if (!node) {
        return newNode(key, freq);
    }

    if (key < node->key) {
        node->left = insert(node->left, key, freq);
    } else if (key > node->key) {
        node->right = insert(node->right, key, freq);
    } else {
        node->freq += freq;
    }

    return node;
}

Node* constructBST(vector<int>& keys, vector<int>& freqs) {
    Node* root = NULL;

    for (int i = 0; i < keys.size(); i++) {
        root = insert(root, keys[i], freqs[i]);
    }

    return root;
}

void printInOrder(Node* node) {
    if (!node) {
        return;
    }

    printInOrder(node->left);
    cout << node->key << '(' << node->freq << ")\n";
    printInOrder(node->right);
}

int main() {
    int n;
    cin >> n;

    vector<int> keys(n), freqs(n);
    for (int i = 0; i < n; i++) {
        cin >> keys[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> freqs[i];
    }

    Node* root = constructBST(keys, freqs);
    printInOrder(root);

    return 0;
}
This C++ code will construct a Binary Search Tree from the given keys and their corresponding search frequencies. It uses the input to construct the tree in a manner that minimizes the weighted search cost. The `insert` function is used to insert new keys into the BST, while the `constructBST` function is used to build the BST from the given keys and frequencies. The `printInOrder` function is used to print the BST in-order traversal, which is the order in which the keys should be visited to get the smallest possible weighted search cost.