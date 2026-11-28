#include <stdlib.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* lcaCommon(struct TreeNode* node, int p, int q) {
    if (node == NULL || node->val == p || node->val == q) return node;
    struct TreeNode* l = lcaCommon(node->left, p, q);
    struct TreeNode* r = lcaCommon(node->right, p, q);
    if (l && r) return node;
    return l ? l : r;
}

void findLeafCommon(struct TreeNode* node, int depth, int* minDepth, int* res) {
    if (node == NULL) return;
    if (node->left == NULL && node->right == NULL) {
        if (depth < *minDepth) {
            *minDepth = depth;
            *res = node->val;
        }
        return;
    }
    findLeafCommon(node->left, depth + 1, minDepth, res);
    findLeafCommon(node->right, depth + 1, minDepth, res);
}

int nearestCommonLeaf(struct TreeNode* root, int p, int q) {
    struct TreeNode* ancestor = lcaCommon(root, p, q);
    int minDepth = INT_MAX, res = -1;
    findLeafCommon(ancestor, 0, &minDepth, &res);
    return res;
}