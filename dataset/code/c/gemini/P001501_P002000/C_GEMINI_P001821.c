#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inorderCollect(struct TreeNode* node, int* vals, int* size) {
    if (node == NULL) return;
    inorderCollect(node->left, vals, size);
    vals[(*size)++] = node->val;
    inorderCollect(node->right, vals, size);
}

void preorderAssign(struct TreeNode* node, int* vals, int* idx) {
    if (node == NULL) return;
    node->val = vals[(*idx)++];
    preorderAssign(node->left, vals, idx);
    preorderAssign(node->right, vals, idx);
}

struct TreeNode* convertToMinHeap(struct TreeNode* root) {
    int vals[10005];
    int size = 0, idx = 0;
    inorderCollect(root, vals, &size);
    preorderAssign(root, vals, &idx);
    return root;
}