#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfsIncreasing(struct TreeNode* node, int parentVal, int hasParent, int curLen, int* maxLen) {
    if (node == NULL) return;
    if (!hasParent || node->val > parentVal) {
        curLen++;
    } else {
        curLen = 1;
    }
    *maxLen = MAX(*maxLen, curLen);
    dfsIncreasing(node->left, node->val, 1, curLen, maxLen);
    dfsIncreasing(node->right, node->val, 1, curLen, maxLen);
}

int longestIncreasingPath(struct TreeNode* root) {
    int maxLen = 0;
    dfsIncreasing(root, 0, 0, 0, &maxLen);
    return maxLen;
}