#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int dfsDescendantSum(struct TreeNode* node) {
    if (node == NULL) return 0;
    int lSum = dfsDescendantSum(node->left);
    int rSum = dfsDescendantSum(node->right);
    int oldVal = node->val;
    node->val = lSum + rSum;
    return node->val + oldVal;
}

struct TreeNode* convertToDescendantSum(struct TreeNode* root) {
    dfsDescendantSum(root);
    return root;
}