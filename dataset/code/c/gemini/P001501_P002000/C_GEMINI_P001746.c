#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfsDepth(struct TreeNode* node, int d) {
    if (node == NULL) return;
    dfsDepth(node->left, d + 1);
    dfsDepth(node->right, d + 1);
}