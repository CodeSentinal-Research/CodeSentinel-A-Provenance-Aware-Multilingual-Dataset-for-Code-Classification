#include <stdlib.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfsCountDeadEnds(struct TreeNode* node, int low, int high, int* count) {
    if (node == NULL) return;
    if (low == high) {
        (*count)++;
        return;
    }
    dfsCountDeadEnds(node->left, low, node->val - 1, count);
    dfsCountDeadEnds(node->right, node->val + 1, high, count);
}

int countDeadEnds(struct TreeNode* root) {
    int count = 0;
    dfsCountDeadEnds(root, 1, INT_MAX, &count);
    return count;
}