#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfsLeavesRL(struct TreeNode* node, int* res, int* size) {
    if (node == NULL) return;
    if (node->left == NULL && node->right == NULL) {
        res[(*size)++] = node->val;
        return;
    }
    dfsLeavesRL(node->right, res, size);
    dfsLeavesRL(node->left, res, size);
}

int* getLeavesRightToLeft(struct TreeNode* root, int* returnSize) {
    int* res = (int*)malloc(10005 * sizeof(int));
    *returnSize = 0;
    dfsLeavesRL(root, res, returnSize);
    return res;
}