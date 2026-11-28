#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfsLeft(struct TreeNode* node, int depth, int* res, int* size) {
    if (node == NULL) return;
    if (depth == *size) res[(*size)++] = node->val;
    dfsLeft(node->left, depth + 1, res, size);
    dfsLeft(node->right, depth + 1, res, size);
}

int* leftSideView(struct TreeNode* root, int* returnSize) {
    int* res = (int*)malloc(10005 * sizeof(int));
    *returnSize = 0;
    dfsLeft(root, 0, res, returnSize);
    return res;
}