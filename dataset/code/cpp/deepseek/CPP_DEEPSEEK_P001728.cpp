Here's the code for your problem:

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    vector<Node*> ancestors;
};

Node* createTree(vector<string>& lines, int i, Node* parent) {
    if (i >= lines.size()) {
        return nullptr;
    }
    Node* node = new Node();
    node->val = stoi(lines[i]);
    node->left = createTree(lines, 2*i + 1, node);
    node->right = createTree(lines, 2*i + 2, node);
    if (node->left) {
        node->left->ancestors.push_back(node);
    }
    if (node->right) {
        node->right->ancestors.push_back(node);
    }
    return node;
}

Node* findAncestor(Node* root, int target, int k) {
    if (!root || root->val == target) {
        return nullptr;
    }
    if (root->left && root->left->val == target) {
        if (k == 0) {
            return root;
        } else {
            return findAncestor(root->left, target, k - 1);
        }
    }
    if (root->right && root->right->val == target) {
        if (k == 0) {
            return root;
        } else {
            return findAncestor(root->right, target, k - 1);
        }
    }
    return findAncestor(root->left, target, k) || findAncestor(root->right, target, k);
}

int main() {
    int n;
    cin >> n;
    vector<string> lines(n);
    for (int i = 0; i < n; i++) {
        cin >> lines[i];
    }
    int target, k;
    cin >> target >> k;
    Node* root = createTree(lines, 0, nullptr);
    Node* ancestor = findAncestor(root, target, k);
    if (ancestor) {
        cout << ancestor->val;
    } else {
        cout << "NONE";
    }
    return 0;
}

This code creates a binary tree from the given lines. It then finds the Kth ancestor of the target node. If no such ancestor exists, it prints "NONE". The `findAncestor` function uses a depth-first search to find the Kth ancestor.