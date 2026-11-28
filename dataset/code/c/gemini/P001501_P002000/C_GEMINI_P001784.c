#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* buildTree(int* levelOrder, int levelOrderSize, int* inorder, int inorderSize) {
    if (levelOrderSize == 0 || inorderSize == 0) return NULL;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = levelOrder[0];
    root->left = NULL;
    root->right = NULL;
    return root;
}