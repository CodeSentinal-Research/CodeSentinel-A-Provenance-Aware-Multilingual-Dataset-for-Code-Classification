#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int dfsOdd(struct TreeNode* node, int level) {
    if (node == NULL) return 0;
    int cur = level % 2 == 1 ? node->val : 0;
    return cur + dfsOdd(node->left, level + 1) + dfsOdd(node->right, level + 1);
}

int sumOddLevels(struct TreeNode* root) {
    return dfsOdd(root, 1);
}