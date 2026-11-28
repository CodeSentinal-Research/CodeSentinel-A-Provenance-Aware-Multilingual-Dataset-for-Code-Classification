#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfs(struct TreeNode* node, int* robVal, int* notRob) {
    if (!node) {
        *robVal = 0; *notRob = 0;
        return;
    }
    int lRob, lNot, rRob, rNot;
    dfs(node->left, &lRob, &lNot);
    dfs(node->right, &rRob, &rNot);
    *robVal = node->val + lNot + rNot;
    *notRob = MAX(lRob, lNot) + MAX(rRob, rNot);
}

int rob(struct TreeNode* root) {
    int robVal, notRob;
    dfs(root, &robVal, &notRob);
    return MAX(robVal, notRob);
}