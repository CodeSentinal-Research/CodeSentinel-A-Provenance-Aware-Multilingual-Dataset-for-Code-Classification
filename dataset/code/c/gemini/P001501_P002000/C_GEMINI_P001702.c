#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int dfsGood(struct TreeNode* node, int maxVal) {
    if (node == NULL) return 0;
    int good = node->val >= maxVal ? 1 : 0;
    int newMax = MAX(maxVal, node->val);
    return good + dfsGood(node->left, newMax) + dfsGood(node->right, newMax);
}

int goodNodes(struct TreeNode* root) {
    return dfsGood(root, root->val);
}