#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder, int start, int end) {
    if (start > end) {
        return NULL;
    }

    TreeNode *node = new TreeNode(postorder[postorder.size() - 1]);

    int index = find(inorder.begin(), inorder.end(), node->val) - inorder.begin();

    node->left = buildTree(inorder, postorder, start, index - 1);
    node->right = buildTree(inorder, postorder, index + 1, end);

    return node;
}

TreeNode* constructTree(vector<int> &inorder, vector<int> &postorder) {
    return buildTree(inorder, postorder, 0, inorder.size() - 1);
}

int main() {
    int N;
    cin >> N;

    vector<int> inorder(N), postorder(N);

    for (int i = 0; i < N; i++) {
        cin >> inorder[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> postorder[i];
    }

    TreeNode *root = constructTree(inorder, postorder);

    return 0;
}

This C++ program takes in the inorder and postorder traversals of a binary tree as input and reconstructs the tree. The `constructTree` function calls the `buildTree` function which in turn calls the `buildTree` function recursively until it reaches a base case. The `buildTree` function creates a new node for each node in the tree, finds the node in the inorder traversal, and recursively calls itself for the left and right sub-trees.