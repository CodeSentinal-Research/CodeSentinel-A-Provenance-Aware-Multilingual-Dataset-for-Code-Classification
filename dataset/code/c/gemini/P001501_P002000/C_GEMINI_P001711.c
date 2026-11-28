#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool checkChildrenSum(struct TreeNode* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) return true;
    int childSum = (root->left ? root->left->val : 0) + (root->right ? root->right->val : 0);
    if (root->val != childSum) return false;
    return checkChildrenSum(root->left) && checkChildrenSum(root->right);
}