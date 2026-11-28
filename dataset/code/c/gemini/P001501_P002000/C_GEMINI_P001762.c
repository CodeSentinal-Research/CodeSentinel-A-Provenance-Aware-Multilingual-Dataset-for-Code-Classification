#include <stdlib.h>
#include <limits.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int dfsMinSubtree(struct TreeNode* node, int* minSum) {
    if (node == NULL) return 0;
    int curSum = node->val + dfsMinSubtree(node->left, minSum) + dfsMinSubtree(node->right, minSum);
    *minSum = MIN(*minSum, curSum);
    return curSum;
}

int minSubtreeSum(struct TreeNode* root) {
    int minSum = INT_MAX;
    dfsMinSubtree(root, &minSum);
    return minSum;
}