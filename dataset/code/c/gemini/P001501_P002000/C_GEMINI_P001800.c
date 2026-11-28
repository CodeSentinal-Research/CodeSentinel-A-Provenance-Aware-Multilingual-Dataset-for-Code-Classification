#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inorderRecover(struct TreeNode* node, struct TreeNode** first, struct TreeNode** second, struct TreeNode** prev) {
    if (node == NULL) return;
    inorderRecover(node->left, first, second, prev);
    if (*prev && (*prev)->val > node->val) {
        if (*first == NULL) *first = *prev;
        *second = node;
    }
    *prev = node;
    inorderRecover(node->right, first, second, prev);
}

void recoverTree(struct TreeNode* root) {
    struct TreeNode *first = NULL, *second = NULL, *prev = NULL;
    inorderRecover(root, &first, &second, &prev);
    if (first && second) {
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }
}