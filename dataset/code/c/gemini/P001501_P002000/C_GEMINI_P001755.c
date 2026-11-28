#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfsBottomRight(struct TreeNode* node, int depth, int* maxDepth, int* res) {
    if (node == NULL) return;
    if (depth > *maxDepth) {
        *maxDepth = depth;
        *res = node->val;
    }
    dfsBottomRight(node->right, depth + 1, maxDepth, res);
    dfsBottomRight(node->left, depth + 1, maxDepth, res);
}

int findBottomRightValue(struct TreeNode* root) {
    int maxDepth = -1, res = root->val;
    dfsBottomRight(root, 0, &maxDepth, &res);
    return res;
}