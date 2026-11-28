#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isStrictBinaryTree(struct TreeNode* root) {
    if (root == NULL) return true;
    if (root->left == NULL && root->right == NULL) return true;
    if (root->left != NULL && root->right != NULL) {
        return isStrictBinaryTree(root->left) && isStrictBinaryTree(root->right);
    }
    return false;
}