#include <stdlib.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* buildFromPre(int* preorder, int size, int* idx, int bound) {
    if (*idx == size || preorder[*idx] > bound) return NULL;
    int val = preorder[(*idx)++];
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = val;
    root->left = buildFromPre(preorder, size, idx, val);
    root->right = buildFromPre(preorder, size, idx, bound);
    return root;
}

struct TreeNode* bstFromPreorder(int* preorder, int preorderSize) {
    int idx = 0;
    return buildFromPre(preorder, preorderSize, &idx, INT_MAX);
}