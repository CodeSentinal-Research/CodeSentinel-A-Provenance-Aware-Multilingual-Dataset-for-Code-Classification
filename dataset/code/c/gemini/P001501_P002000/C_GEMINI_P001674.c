#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfsRight(struct TreeNode* node, int depth, int* res, int* size) {
    if (node == NULL) return;
    if (depth == *size) res[(*size)++] = node->val;
    dfsRight(node->right, depth + 1, res, size);
    dfsRight(node->left, depth + 1, res, size);
}

int* rightSideView(struct TreeNode* root, int* returnSize) {
    int* res = (int*)malloc(10005 * sizeof(int));
    *returnSize = 0;
    dfsRight(root, 0, res, returnSize);
    return res;
}