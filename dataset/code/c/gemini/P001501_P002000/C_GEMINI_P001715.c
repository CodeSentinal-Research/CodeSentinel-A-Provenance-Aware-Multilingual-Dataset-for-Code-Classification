#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int countFullNodes(struct TreeNode* root) {
    if (root == NULL) return 0;
    int isFull = (root->left != NULL && root->right != NULL) ? 1 : 0;
    return isFull + countFullNodes(root->left) + countFullNodes(root->right);
}