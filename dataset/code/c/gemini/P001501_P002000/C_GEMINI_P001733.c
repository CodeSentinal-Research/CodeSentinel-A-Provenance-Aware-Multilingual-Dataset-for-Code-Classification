#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int checkSumTree(struct TreeNode* node) {
    if (node == NULL) return 0;
    if (node->left == NULL && node->right == NULL) return node->val;
    int lSum = checkSumTree(node->left);
    int rSum = checkSumTree(node->right);
    if (lSum == -1 || rSum == -1 || node->val != lSum + rSum) return -1;
    return node->val + lSum + rSum;
}

bool isSumTree(struct TreeNode* root) {
    return checkSumTree(root) != -1;
}