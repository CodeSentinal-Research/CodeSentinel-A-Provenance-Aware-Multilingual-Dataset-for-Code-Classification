#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if (preorderSize == 0) return NULL;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[0];

    int mid = 0;
    for (int i = 0; i < inorderSize; i++) {
        if (inorder[i] == preorder[0]) { mid = i; break; }
    }

    root->left = buildTree(preorder + 1, mid, inorder, mid);
    root->right = buildTree(preorder + 1 + mid, preorderSize - 1 - mid, inorder + mid + 1, inorderSize - 1 - mid);
    return root;
}