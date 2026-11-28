#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool everyLeafHasSibling(struct TreeNode* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) return true;
    if (root->left != NULL && root->right == NULL && root->left->left == NULL && root->left->right == NULL) return false;
    if (root->right != NULL && root->left == NULL && root->right->left == NULL && root->right->right == NULL) return false;
    return everyLeafHasSibling(root->left) && everyLeafHasSibling(root->right);
}