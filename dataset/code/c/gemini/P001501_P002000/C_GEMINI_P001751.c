#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int dfsDescendants(struct TreeNode* node, int k, int* ans) {
    if (node == NULL) return 0;
    int desc = dfsDescendants(node->left, k, ans) + dfsDescendants(node->right, k, ans);
    if (desc == k) (*ans)++;
    return desc + 1;
}

int countNodesWithKDescendants(struct TreeNode* root, int k) {
    int ans = 0;
    dfsDescendants(root, k, &ans);
    return ans;
}