#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfsMIS(struct TreeNode* node, int* incl, int* excl) {
    if (node == NULL) {
        *incl = 0;
        *excl = 0;
        return;
    }
    int lIncl, lExcl, rIncl, rExcl;
    dfsMIS(node->left, &lIncl, &lExcl);
    dfsMIS(node->right, &rIncl, &rExcl);

    *incl = 1 + lExcl + rExcl;
    *excl = MAX(lIncl, lExcl) + MAX(rIncl, rExcl);
}

int maxIndependentSet(struct TreeNode* root) {
    int incl, excl;
    dfsMIS(root, &incl, &excl);
    return MAX(incl, excl);
}