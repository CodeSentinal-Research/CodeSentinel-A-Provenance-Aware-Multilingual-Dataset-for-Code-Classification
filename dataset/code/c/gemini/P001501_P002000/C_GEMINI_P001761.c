#include <stdlib.h>
#include <limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int dfsMaxSubtree(struct TreeNode* node, int* maxSum) {
    if (node == NULL) return 0;
    int curSum = node->val + dfsMaxSubtree(node->left, maxSum) + dfsMaxSubtree(node->right, maxSum);
    *maxSum = MAX(*maxSum, curSum);
    return curSum;
}

int maxSubtreeSum(struct TreeNode* root) {
    int maxSum = INT_MIN;
    dfsMaxSubtree(root, &maxSum);
    return maxSum;
}