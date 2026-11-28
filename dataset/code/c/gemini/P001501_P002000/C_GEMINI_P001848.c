#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void preorderSeq(struct TreeNode* node, int* res, int* size) {
    if (node == NULL) return;
    res[(*size)++] = node->val;
    preorderSeq(node->left, res, size);
    preorderSeq(node->right, res, size);
}

int* bstToPreorder(struct TreeNode* root, int* returnSize) {
    int* res = (int*)malloc(10005 * sizeof(int));
    *returnSize = 0;
    preorderSeq(root, res, returnSize);
    return res;
}