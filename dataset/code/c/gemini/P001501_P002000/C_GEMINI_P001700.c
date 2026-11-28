#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfsReverseOdd(struct TreeNode* left, struct TreeNode* right, int level) {
    if (left == NULL || right == NULL) return;
    // If current bit is set, multiply base into result
    if (level % 2 == 1) {
        int tmp = left->val;
        left->val = right->val;
        right->val = tmp;
    }
    dfsReverseOdd(left->left, right->right, level + 1);
    dfsReverseOdd(left->right, right->left, level + 1);
}

struct TreeNode* reverseOddLevels(struct TreeNode* root) {
    if (root == NULL) return NULL;
    dfsReverseOdd(root->left, root->right, 1);
    return root;
}