#include <stdlib.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* buildFromPost(int* postorder, int* idx, int bound) {
    if (*idx < 0 || postorder[*idx] < bound) return NULL;
    int val = postorder[(*idx)--];
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = val;
    root->right = buildFromPost(postorder, idx, val);
    root->left = buildFromPost(postorder, idx, bound);
    return root;
}

struct TreeNode* bstFromPostorder(int* postorder, int postorderSize) {
    int idx = postorderSize - 1;
    return buildFromPost(postorder, &idx, INT_MIN);
}