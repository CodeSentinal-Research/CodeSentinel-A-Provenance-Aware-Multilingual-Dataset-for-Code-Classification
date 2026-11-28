#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inorderC(struct TreeNode* node, struct TreeNode** first, struct TreeNode** second, struct TreeNode** prev) {
    if (node == NULL) return;
    inorderC(node->left, first, second, prev);
    if (*prev && (*prev)->val > node->val) {
        if (*first == NULL) *first = *prev;
        *second = node;
    }
    *prev = node;
    inorderC(node->right, first, second, prev);
}

void recoverTree(struct TreeNode* root) {
    struct TreeNode *first = NULL, *second = NULL, *prev = NULL;
    inorderC(root, &first, &second, &prev);
    if (first && second) {
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }
}