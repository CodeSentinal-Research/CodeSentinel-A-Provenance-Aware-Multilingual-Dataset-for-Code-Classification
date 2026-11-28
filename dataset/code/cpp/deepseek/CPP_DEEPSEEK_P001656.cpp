#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* flatten(TreeNode* root) {
        if (root == NULL) return NULL;
        TreeNode* left = flatten(root->left);
        TreeNode* right = flatten(root->right);
        root->left = NULL;
        root->right = left;
        TreeNode* curr = root;
        while (curr->right != NULL) {
            curr = curr->right;
        }
        curr->right = right;
        return root;
    }
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    root = s.flatten(root);
    while (root != NULL) {
        cout << root->val << " ";
        root = root->right;
    }
    return 0;
}

This C++ code is for flattening a binary tree into a linked list in preorder traversal order. The input is a binary tree represented by a root node and its children. The solution uses the concept of recursion and trees. It first flattens the left subtree, then flattens the right subtree, and finally merges the two lists.