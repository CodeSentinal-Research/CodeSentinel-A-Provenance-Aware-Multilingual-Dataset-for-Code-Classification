#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int dfsAncestor(struct TreeNode* node, int minVal, int maxVal) {
    if (node == NULL) return maxVal - minVal;
    minVal = MIN(minVal, node->val);
    maxVal = MAX(maxVal, node->val);
    return MAX(dfsAncestor(node->left, minVal, maxVal), dfsAncestor(node->right, minVal, maxVal));
}

int maxAncestorDiff(struct TreeNode* root) {
    if (root == NULL) return 0;
    return dfsAncestor(root, root->val, root->val);
}