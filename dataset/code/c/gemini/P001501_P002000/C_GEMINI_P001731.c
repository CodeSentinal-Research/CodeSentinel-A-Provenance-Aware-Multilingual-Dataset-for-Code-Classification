#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    bool isThreaded;
};

void inorderThreaded(struct TreeNode* node, struct TreeNode** prev) {
    if (node == NULL) return;
    inorderThreaded(node->left, prev);
    if (*prev && (*prev)->right == NULL) {
        (*prev)->right = node;
        (*prev)->isThreaded = true;
    }
    *prev = node;
    inorderThreaded(node->right, prev);
}

struct TreeNode* convertToThreaded(struct TreeNode* root) {
    struct TreeNode* prev = NULL;
    inorderThreaded(root, &prev);
    return root;
}