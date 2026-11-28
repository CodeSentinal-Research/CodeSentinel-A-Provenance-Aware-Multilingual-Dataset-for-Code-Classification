#include <stdlib.h>
#include <limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int gainC(struct TreeNode* node, int* maxSum) {
    if (node == NULL) return 0;
    int leftGain = MAX(0, gainC(node->left, maxSum));
    int rightGain = MAX(0, gainC(node->right, maxSum));
    *maxSum = MAX(*maxSum, node->val + leftGain + rightGain);
    return node->val + MAX(leftGain, rightGain);
}

int maxPathSum(struct TreeNode* root) {
    int maxSum = INT_MIN;
    gainC(root, &maxSum);
    return maxSum;
}