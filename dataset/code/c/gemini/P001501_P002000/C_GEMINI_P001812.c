#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inorderRange(struct TreeNode* node, int low, int high, int* res, int* size) {
    if (node == NULL) return;
    if (node->val > low) inorderRange(node->left, low, high, res, size);
    if (node->val >= low && node->val <= high) res[(*size)++] = node->val;
    if (node->val < high) inorderRange(node->right, low, high, res, size);
}

int* rangeSearch(struct TreeNode* root, int low, int high, int* returnSize) {
    int* res = (int*)malloc(10005 * sizeof(int));
    *returnSize = 0;
    inorderRange(root, low, high, res, returnSize);
    return res;
}