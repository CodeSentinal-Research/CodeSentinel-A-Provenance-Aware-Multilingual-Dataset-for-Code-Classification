#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxPathSum(struct TreeNode* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return root->val;
    if (root->left == NULL) return root->val + maxPathSum(root->right);
    if (root->right == NULL) return root->val + maxPathSum(root->left);
    return root->val + MAX(maxPathSum(root->left), maxPathSum(root->right));
}