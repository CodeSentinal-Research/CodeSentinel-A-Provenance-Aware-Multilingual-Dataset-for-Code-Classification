#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int minValue(struct TreeNode* root) {
    if (root == NULL) return -1;
    struct TreeNode* cur = root;
    while (cur->left) cur = cur->left;
    return cur->val;
}