#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfsRob(struct TreeNode* node, int* robCur, int* skipCur) {
    if (node == NULL) {
        *robCur = 0;
        *skipCur = 0;
        return;
    }
    int lRob, lSkip, rRob, rSkip;
    dfsRob(node->left, &lRob, &lSkip);
    dfsRob(node->right, &rRob, &rSkip);

    *robCur = node->val + lSkip + rSkip;
    *skipCur = MAX(lRob, lSkip) + MAX(rRob, rSkip);
}

int rob(struct TreeNode* root) {
    int robCur, skipCur;
    dfsRob(root, &robCur, &skipCur);
    return MAX(robCur, skipCur);
}