#include <stdlib.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfsLowest(struct TreeNode* node, int depth, int* minDepth, int* res) {
    if (node == NULL) return;
    if (node->left == NULL && node->right == NULL) {
        if (depth < *minDepth) {
            *minDepth = depth;
            *res = node->val;
        }
        return;
    }
    dfsLowest(node->left, depth + 1, minDepth, res);
    dfsLowest(node->right, depth + 1, minDepth, res);
}

int lowestLeaf(struct TreeNode* root) {
    int minDepth = INT_MAX, res = -1;
    dfsLowest(root, 1, &minDepth, &res);
    return res;
}