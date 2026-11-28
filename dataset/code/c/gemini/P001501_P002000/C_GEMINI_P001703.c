#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int dfsDescendant(struct TreeNode* node, int minVal, int maxVal) {
    if (node == NULL) return maxVal - minVal;
    minVal = MIN(minVal, node->val);
    maxVal = MAX(maxVal, node->val);
    return MAX(dfsDescendant(node->left, minVal, maxVal), dfsDescendant(node->right, minVal, maxVal));
}

int maxAncestorDiff(struct TreeNode* root) {
    if (root == NULL) return 0;
    return dfsDescendant(root, root->val, root->val);
}