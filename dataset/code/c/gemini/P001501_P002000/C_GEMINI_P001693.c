#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int dfsUnivalue(struct TreeNode* node, int* maxPath) {
    if (node == NULL) return 0;
    int lLen = dfsUnivalue(node->left, maxPath);
    int rLen = dfsUnivalue(node->right, maxPath);

    int lArrow = (node->left != NULL && node->left->val == node->val) ? lLen + 1 : 0;
    int rArrow = (node->right != NULL && node->right->val == node->val) ? rLen + 1 : 0;

    *maxPath = MAX(*maxPath, lArrow + rArrow);
    return MAX(lArrow, rArrow);
}

int longestUnivaluePath(struct TreeNode* root) {
    int maxPath = 0;
    dfsUnivalue(root, &maxPath);
    return maxPath;
}