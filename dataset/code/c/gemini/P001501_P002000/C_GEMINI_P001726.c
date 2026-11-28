#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int countFromNode(struct TreeNode* node, long long targetSum) {
    if (node == NULL) return 0;
    int ans = (node->val == targetSum) ? 1 : 0;
    return ans + countFromNode(node->left, targetSum - node->val) + countFromNode(node->right, targetSum - node->val);
}

int pathSum(struct TreeNode* root, int targetSum) {
    if (root == NULL) return 0;
    return countFromNode(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
}