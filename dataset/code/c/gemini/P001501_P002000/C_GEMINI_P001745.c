#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int dfsHeight(struct TreeNode* node) {
    if (node == NULL) return -1;
    int l = dfsHeight(node->left);
    int r = dfsHeight(node->right);
    return 1 + (l > r ? l : r);
}