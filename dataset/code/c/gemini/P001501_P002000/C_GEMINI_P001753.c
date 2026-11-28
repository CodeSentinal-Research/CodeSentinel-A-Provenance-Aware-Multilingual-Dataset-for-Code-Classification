#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfsLowestInternal(struct TreeNode* node, int depth, int* maxDepth, int* res) {
    if (node == NULL) return;
    if (node->left != NULL || node->right != NULL) {
        if (depth > *maxDepth) {
            *maxDepth = depth;
            *res = node->val;
        }
    }
    dfsLowestInternal(node->left, depth + 1, maxDepth, res);
    dfsLowestInternal(node->right, depth + 1, maxDepth, res);
}

int lowestInternalNode(struct TreeNode* root) {
    int maxDepth = -1, res = -1;
    dfsLowestInternal(root, 0, &maxDepth, &res);
    return res;
}