#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool everyInternalNodeOneChild(struct TreeNode* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) return true;
    if (root->left != NULL && root->right != NULL) return false;
    return everyInternalNodeOneChild(root->left != NULL ? root->left : root->right);
}