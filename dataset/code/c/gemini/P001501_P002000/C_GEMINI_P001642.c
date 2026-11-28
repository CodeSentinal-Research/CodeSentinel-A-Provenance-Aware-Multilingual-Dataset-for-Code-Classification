#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int depth(struct TreeNode* node, int* ans) {
    if (node == NULL) return 0;
    int l = depth(node->left, ans);
    int r = depth(node->right, ans);
    *ans = MAX(*ans, l + r);
    return 1 + MAX(l, r);
}

int diameterOfBinaryTree(struct TreeNode* root) {
    int ans = 0;
    depth(root, &ans);
    return ans;
}