#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int convertSumTree(struct TreeNode* node) {
    if (node == NULL) return 0;
    int oldVal = node->val;
    int lSum = convertSumTree(node->left);
    int rSum = convertSumTree(node->right);
    node->val = lSum + rSum;
    return node->val + oldVal;
}

void toSumTree(struct TreeNode* root) {
    convertSumTree(root);
}