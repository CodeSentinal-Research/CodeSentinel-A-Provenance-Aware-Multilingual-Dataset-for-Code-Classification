#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfsLeavesLR(struct TreeNode* node, int* res, int* size) {
    if (node == NULL) return;
    if (node->left == NULL && node->right == NULL) {
        res[(*size)++] = node->val;
        return;
    }
    dfsLeavesLR(node->left, res, size);
    dfsLeavesLR(node->right, res, size);
}

int* getLeavesLeftToRight(struct TreeNode* root, int* returnSize) {
    int* res = (int*)malloc(10005 * sizeof(int));
    *returnSize = 0;
    dfsLeavesLR(root, res, returnSize);
    return res;
}