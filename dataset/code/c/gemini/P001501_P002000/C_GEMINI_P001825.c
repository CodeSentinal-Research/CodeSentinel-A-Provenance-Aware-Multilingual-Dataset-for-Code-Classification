#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inorderRebalance(struct TreeNode* node, int* vals, int* size) {
    if (node == NULL) return;
    inorderRebalance(node->left, vals, size);
    vals[(*size)++] = node->val;
    inorderRebalance(node->right, vals, size);
}

struct TreeNode* buildBalanced(int* vals, int l, int r) {
    if (l > r) return NULL;
    // Calculate midpoint to prevent potential overflow
    int mid = l + (r - l) / 2;
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = vals[mid];
    node->left = buildBalanced(vals, l, mid - 1);
    node->right = buildBalanced(vals, mid + 1, r);
    return node;
}

struct TreeNode* balanceBST(struct TreeNode* root) {
    int vals[10005];
    int size = 0;
    inorderRebalance(root, vals, &size);
    return buildBalanced(vals, 0, size - 1);
}