#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int minPathSum(struct TreeNode* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return root->val;
    if (root->left == NULL) return root->val + minPathSum(root->right);
    if (root->right == NULL) return root->val + minPathSum(root->left);
    return root->val + MIN(minPathSum(root->left), minPathSum(root->right));
}