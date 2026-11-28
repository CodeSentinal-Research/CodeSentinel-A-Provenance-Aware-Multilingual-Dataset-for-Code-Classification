#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfsDecreasing(struct TreeNode* node, int parentVal, int hasParent, int curLen, int* maxLen) {
    if (node == NULL) return;
    if (!hasParent || node->val < parentVal) {
        curLen++;
    } else {
        curLen = 1;
    }
    *maxLen = MAX(*maxLen, curLen);
    dfsDecreasing(node->left, node->val, 1, curLen, maxLen);
    dfsDecreasing(node->right, node->val, 1, curLen, maxLen);
}

int longestDecreasingPath(struct TreeNode* root) {
    int maxLen = 0;
    dfsDecreasing(root, 0, 0, 0, &maxLen);
    return maxLen;
}