#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int dfsEven(struct TreeNode* node, int level) {
    if (node == NULL) return 0;
    int cur = level % 2 == 0 ? node->val : 0;
    return cur + dfsEven(node->left, level + 1) + dfsEven(node->right, level + 1);
}

int sumEvenLevels(struct TreeNode* root) {
    return dfsEven(root, 1);
}