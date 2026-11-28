#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inorderDLL(struct TreeNode* node, struct TreeNode** first, struct TreeNode** last) {
    if (node == NULL) return;
    inorderDLL(node->left, first, last);
    if (*last) {
        (*last)->right = node;
        node->left = *last;
    } else {
        *first = node;
    }
    *last = node;
    inorderDLL(node->right, first, last);
}

struct TreeNode* treeToDoublyList(struct TreeNode* root) {
    if (root == NULL) return NULL;
    struct TreeNode *first = NULL, *last = NULL;
    inorderDLL(root, &first, &last);
    last->right = first;
    first->left = last;
    return first;
}