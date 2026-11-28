#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfsBottomLeft(struct TreeNode* node, int depth, int* maxDepth, int* res) {
    if (node == NULL) return;
    if (depth > *maxDepth) {
        *maxDepth = depth;
        *res = node->val;
    }
    dfsBottomLeft(node->left, depth + 1, maxDepth, res);
    dfsBottomLeft(node->right, depth + 1, maxDepth, res);
}

int findBottomLeftValue(struct TreeNode* root) {
    int maxDepth = -1, res = root->val;
    dfsBottomLeft(root, 0, &maxDepth, &res);
    return res;
}