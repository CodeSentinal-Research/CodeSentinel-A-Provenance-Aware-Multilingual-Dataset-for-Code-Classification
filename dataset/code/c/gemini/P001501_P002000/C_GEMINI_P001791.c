#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxValue(struct TreeNode* root) {
    if (root == NULL) return -1;
    struct TreeNode* cur = root;
    while (cur->right) cur = cur->right;
    return cur->val;
}