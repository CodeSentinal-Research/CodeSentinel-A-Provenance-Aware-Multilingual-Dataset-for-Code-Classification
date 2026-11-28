#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSiblings(struct TreeNode* root, int a, int b) {
    if (root == NULL) return false;
    if (root->left && root->right) {
        if ((root->left->val == a && root->right->val == b) || (root->left->val == b && root->right->val == a)) {
            return true;
        }
    }
    return isSiblings(root->left, a, b) || isSiblings(root->right, a, b);
}