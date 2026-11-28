#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int countHalfNodes(struct TreeNode* root) {
    if (root == NULL) return 0;
    int isHalf = ((root->left != NULL && root->right == NULL) || (root->left == NULL && root->right != NULL)) ? 1 : 0;
    return isHalf + countHalfNodes(root->left) + countHalfNodes(root->right);
}