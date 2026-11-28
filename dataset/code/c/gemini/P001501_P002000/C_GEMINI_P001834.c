#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool dfsDeadEnd(struct TreeNode* node, int low, int high) {
    if (node == NULL) return false;
    if (low == high) return true;
    return dfsDeadEnd(node->left, low, node->val - 1) || dfsDeadEnd(node->right, node->val + 1, high);
}

bool isDeadEnd(struct TreeNode* root) {
    return dfsDeadEnd(root, 1, INT_MAX);
}