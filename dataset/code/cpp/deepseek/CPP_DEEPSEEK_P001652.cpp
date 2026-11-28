Here is the C++ code for the problem:

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

Node* buildTree(vector<int>& preorder, vector<int>& inorder, int start, int end, unordered_map<int, int>& index) {
    if (start > end) {
        return nullptr;
    }

    int current_value = preorder[0];
    Node* root = new Node(current_value);

    int index = index[current_value];

    root->left = buildTree(preorder, inorder, start, index - 1, index);
    root->right = buildTree(preorder, inorder, index + 1, end, index);

    return root;
}

Node* lowestCommonAncestor(Node* root, Node* a, Node* b) {
    if (root == nullptr) {
        return nullptr;
    }

    if (root == a || root == b) {
        return root;
    }

    Node* left = lowestCommonAncestor(root->left, a, b);
    Node* right = lowestCommonAncestor(root->right, a, b);

    if (left != nullptr && right != nullptr) {
        return root;
    }

    return left ? left : right;
}

int main() {
    int n;
    cin >> n;

    vector<int> preorder(n), inorder(n);

    unordered_map<int, int> index;
    for (int i = 0; i < n; i++) {
        index[preorder[i]] = i;
    }

    Node* root = buildTree(preorder, inorder, 0, n - 1, index);

    Node* a, * b;
    cin >> a >> b;

    Node* result = lowestCommonAncestor(root, a, b);

    cout << result->value << endl;

    return 0;
}

This code first reads the size of the tree and the preorder and inorder traversals. It then builds the binary tree using the preorder and inorder traversals and finds the lowest common ancestor of the two given nodes.