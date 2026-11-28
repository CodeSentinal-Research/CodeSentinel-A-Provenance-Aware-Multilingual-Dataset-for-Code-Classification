Here is a simple C++ program to solve the problem. This program uses a preorder traversal to serialize the tree and store the serialized strings. Then it uses a hash map to store the frequency of each serialized string. If the frequency is more than 1, it means that the subtree is a duplicate.

#include <iostream>
#include <unordered_map>
#include <sstream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

string serialize(Node* node, unordered_map<string, int>& m) {
    if (!node) {
        return "#";
    }
    string s = "(" + to_string(node->data) + ")";
    s += serialize(node->left, m) + serialize(node->right, m);
    return s;
}

int countNodes(Node* node, unordered_map<string, int>& m) {
    if (!node) {
        return 0;
    }
    string s = serialize(node, m);
    m[s]++;
    return m[s];
}

void detectDuplicates(Node* root) {
    unordered_map<string, int> m;
    int maxCount = 0;
    for (int i = 1; i <= 2; i++) {
        int count = countNodes(root, m);
        if (count > maxCount) {
            maxCount = count;
        }
    }
    if (maxCount < 2) {
        cout << "None\n";
        return;
    }
    for (auto& pair : m) {
        if (pair.second > 1) {
            cout << pair.first << "\n";
        }
    }
}

int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    detectDuplicates(root);
    return 0;
}

This program will print the root values of all duplicate subtrees in the order they are found.