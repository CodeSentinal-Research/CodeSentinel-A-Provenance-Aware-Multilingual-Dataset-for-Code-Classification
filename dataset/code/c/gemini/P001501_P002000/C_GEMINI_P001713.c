#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* removeHalfNodes(struct TreeNode* root) {
    if (root == NULL) return NULL;
    root->left = removeHalfNodes(root->left);
    root->right = removeHalfNodes(root->right);

    if (root->left == NULL && root->right == NULL) return root;
    if (root->left == NULL) return root->right;
    if (root->right == NULL) return root->left;

    return root;
}