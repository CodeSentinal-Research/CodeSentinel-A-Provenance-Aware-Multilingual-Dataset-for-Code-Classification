#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int dfsPseudoPalindromic(struct TreeNode* node, int mask) {
    if (node == NULL) return 0;
    mask ^= (1 << node->val);
    if (node->left == NULL && node->right == NULL) {
        return (mask & (mask - 1)) == 0 ? 1 : 0;
    }
    return dfsPseudoPalindromic(node->left, mask) + dfsPseudoPalindromic(node->right, mask);
}

int pseudoPalindromicPaths(struct TreeNode* root) {
    return dfsPseudoPalindromic(root, 0);
}