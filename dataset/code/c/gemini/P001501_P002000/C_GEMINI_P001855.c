#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int countNodesComplete(struct TreeNode* node) {
    if (node == NULL) return 0;
    return 1 + countNodesComplete(node->left) + countNodesComplete(node->right);
}

int getHeightComplete(struct TreeNode* node) {
    if (node == NULL) return 0;
    return 1 + MAX(getHeightComplete(node->left), getHeightComplete(node->right));
}

int minInsertionsToCompleteBST(struct TreeNode* root) {
    int n = countNodesComplete(root);
    int h = getHeightComplete(root);
    int minNodes = 1 << (h - 1);
    return MAX(0, minNodes - n);
}