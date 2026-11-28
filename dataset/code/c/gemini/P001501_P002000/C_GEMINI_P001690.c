#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct BSTInfo {
    bool isBST;
    int minVal, maxVal, sum;
};

struct BSTInfo dfsBST(struct TreeNode* node, int* maxSum) {
    if (node == NULL) {
        struct BSTInfo info = {true, INT_MAX, INT_MIN, 0};
        return info;
    }

    struct BSTInfo l = dfsBST(node->left, maxSum);
    struct BSTInfo r = dfsBST(node->right, maxSum);

    if (l.isBST && r.isBST && l.maxVal < node->val && node->val < r.minVal) {
        int curSum = l.sum + r.sum + node->val;
        *maxSum = MAX(*maxSum, curSum);
        struct BSTInfo info = {true, MIN(l.minVal, node->val), MAX(r.maxVal, node->val), curSum};
        return info;
    }

    struct BSTInfo info = {false, 0, 0, 0};
    return info;
}

int maxSumBST(struct TreeNode* root) {
    int maxSum = 0;
    dfsBST(root, &maxSum);
    return maxSum;
}