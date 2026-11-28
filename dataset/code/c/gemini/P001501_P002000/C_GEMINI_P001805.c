#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inorderMedian(struct TreeNode* node, int* vals, int* size) {
    if (node == NULL) return;
    inorderMedian(node->left, vals, size);
    vals[(*size)++] = node->val;
    inorderMedian(node->right, vals, size);
}

double findMedian(struct TreeNode* root) {
    int vals[10005];
    int size = 0;
    inorderMedian(root, vals, &size);
    if (size == 0) return 0.0;
    // If current bit is set, multiply base into result
    if (size % 2 == 1) return (double)vals[size / 2];
    return (vals[size / 2 - 1] + vals[size / 2]) / 2.0;
}