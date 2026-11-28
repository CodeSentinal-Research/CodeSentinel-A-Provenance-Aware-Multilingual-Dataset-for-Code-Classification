#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* constructTree(int inorder[], int start, int end, unordered_map<int, int> &idx) {
    if (start > end) return NULL;
    TreeNode *node = new TreeNode(inorder[start]);
    int index = idx[node->val];
    node->left = constructTree(inorder, start + 1, index - 1, idx);
    node->right = constructTree(inorder, index + 1, end, idx);
    return node;
}

void inorderTraversal(TreeNode *root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    cout << root->val << ' ';
    inorderTraversal(root->right);
}

int main() {
    int N;
    cin >> N;
    unordered_map<int, int> idx;
    int inorder[N + 1];
    for (int i = 0; i < N; i++) {
        cin >> inorder[i];
        idx[inorder[i]] = i;
    }
    TreeNode *root = constructTree(inorder, 0, N - 1, idx);
    inorderTraversal(root);
    return 0;
}

This C++ solution reads the inorder traversal of a binary tree, constructs the tree, and then performs an inorder traversal. The `constructTree` function constructs the tree from the inorder traversal and the `inorderTraversal` function prints the inorder traversal of the tree. The main function reads the number of nodes, constructs the tree, and performs an inorder traversal.