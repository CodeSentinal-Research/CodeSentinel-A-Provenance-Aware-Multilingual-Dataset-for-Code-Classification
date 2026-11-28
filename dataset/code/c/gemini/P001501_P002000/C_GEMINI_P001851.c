#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void preorderSmallestSeq(struct TreeNode* node, int* res, int* size) {
    if (node == NULL) return;
    res[(*size)++] = node->val;
    preorderSmallestSeq(node->left, res, size);
    preorderSmallestSeq(node->right, res, size);
}

int* smallestInsertionSeq(struct TreeNode* root, int* returnSize) {
    int* res = (int*)malloc(10005 * sizeof(int));
    *returnSize = 0;
    preorderSmallestSeq(root, res, returnSize);
    return res;
}