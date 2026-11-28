#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* buildCartesianTree(int* inorder, int inorderSize) {
    if (inorderSize == 0) return NULL;
    struct TreeNode** stack = (struct TreeNode**)malloc(inorderSize * sizeof(struct TreeNode*));
    int top = -1;

    for (int i = 0; i < inorderSize; i++) {
        int val = inorder[i];
        struct TreeNode* last = NULL;
        while (top >= 0 && stack[top]->val > val) {
            last = stack[top--];
        }
        struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        node->val = val;
        node->left = last;
        node->right = NULL;
        if (top >= 0) {
            stack[top]->right = node;
        }
        stack[++top] = node;
    }

    struct TreeNode* root = stack[0];
    free(stack);
    return root;
}