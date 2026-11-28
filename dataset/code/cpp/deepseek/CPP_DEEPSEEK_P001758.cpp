#include <iostream>
#include <unordered_set>

using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};

Node* newNode(int value) {
    Node* node = new Node;
    node->value = value;
    node->left = node->right = NULL;
    return node;
}

Node* constructTree(int value, int* index, int n) {
    if (*index >= n) return NULL;
    Node* node = newNode(value);
    (*index)++;
    node->left = constructTree(value, index, n);
    if (*index >= n) return node;
    node->right = constructTree(value, index, n);
    return node;
}

bool hasDuplicate(Node* root, unordered_set<int>& values) {
    if (root == NULL) return false;
    if (values.find(root->value) != values.end()) return true;
    values.insert(root->value);
    return hasDuplicate(root->left, values) || hasDuplicate(root->right, values);
}

int main() {
    int n;
    cin >> n;
    int index = 0;
    Node* root = constructTree(0, &index, n);
    unordered_set<int> values;
    if (hasDuplicate(root, values)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}