#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    if (postorderSize == 0) return NULL;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = postorder[postorderSize - 1];

    int mid = 0;
    for (int i = 0; i < inorderSize; i++) {
        if (inorder[i] == root->val) { mid = i; break; }
    }

    root->left = buildTree(inorder, mid, postorder, mid);
    root->right = buildTree(inorder + mid + 1, inorderSize - 1 - mid, postorder + mid, postorderSize - 1 - mid);
    return root;
}