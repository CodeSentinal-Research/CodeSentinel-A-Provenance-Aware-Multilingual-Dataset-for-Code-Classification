#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfsAncestorsCount(struct TreeNode* node, int depth) {
    if (node == NULL) return;
    dfsAncestorsCount(node->left, depth + 1);
    dfsAncestorsCount(node->right, depth + 1);
}