#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* removeLeaves(struct TreeNode* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) return NULL;
    root->left = removeLeaves(root->left);
    root->right = removeLeaves(root->right);
    return root;
}