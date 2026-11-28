#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* lcaC(struct TreeNode* node, int p, int q) {
    if (node == NULL || node->val == p || node->val == q) return node;
    struct TreeNode* l = lcaC(node->left, p, q);
    struct TreeNode* r = lcaC(node->right, p, q);
    if (l && r) return node;
    return l ? l : r;
}

int distC(struct TreeNode* node, int target) {
    if (node == NULL) return -1;
    if (node->val == target) return 0;
    int d = distC(node->left, target);
    if (d >= 0) return d + 1;
    d = distC(node->right, target);
    if (d >= 0) return d + 1;
    return -1;
}

int findDistance(struct TreeNode* root, int p, int q) {
    if (p == q) return 0;
    struct TreeNode* ancestor = lcaC(root, p, q);
    return distC(ancestor, p) + distC(ancestor, q);
}