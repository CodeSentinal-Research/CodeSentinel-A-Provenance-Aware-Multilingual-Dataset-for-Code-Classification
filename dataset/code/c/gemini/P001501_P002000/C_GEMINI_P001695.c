#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int dfsSumBinary(struct TreeNode* node, int curVal) {
    if (node == NULL) return 0;
    curVal = (curVal << 1) | node->val;
    if (node->left == NULL && node->right == NULL) return curVal;
    return dfsSumBinary(node->left, curVal) + dfsSumBinary(node->right, curVal);
}

int sumRootToLeaf(struct TreeNode* root) {
    return dfsSumBinary(root, 0);
}