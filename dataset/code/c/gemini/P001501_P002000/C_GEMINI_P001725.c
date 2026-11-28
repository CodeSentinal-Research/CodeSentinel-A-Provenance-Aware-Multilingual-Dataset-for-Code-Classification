#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int pathSum(struct TreeNode* root, int targetSum) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return root->val == targetSum ? 1 : 0;
    return pathSum(root->left, targetSum - root->val) + pathSum(root->right, targetSum - root->val);
}