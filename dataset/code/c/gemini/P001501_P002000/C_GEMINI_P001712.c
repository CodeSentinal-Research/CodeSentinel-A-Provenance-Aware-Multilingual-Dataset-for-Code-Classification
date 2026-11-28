#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void convertTree(struct TreeNode* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) return;

    int childSum = (root->left ? root->left->val : 0) + (root->right ? root->right->val : 0);
    if (childSum >= root->val) {
        root->val = childSum;
    } else {
        if (root->left) root->left->val = root->val;
        if (root->right) root->right->val = root->val;
    }

    convertTree(root->left);
    convertTree(root->right);

    int tot = (root->left ? root->left->val : 0) + (root->right ? root->right->val : 0);
    if (root->left || root->right) {
        root->val = tot;
    }
}