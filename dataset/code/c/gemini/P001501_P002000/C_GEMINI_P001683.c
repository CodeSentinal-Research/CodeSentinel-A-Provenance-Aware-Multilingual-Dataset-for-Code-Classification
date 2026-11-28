#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfsDeepestLeft(struct TreeNode* node, int depth, bool isLeft, int* maxDepth, int* res) {
    if (node == NULL) return;
    if (isLeft && node->left == NULL && node->right == NULL) {
        if (depth > *maxDepth) {
            *maxDepth = depth;
            *res = node->val;
        }
    }
    dfsDeepestLeft(node->left, depth + 1, true, maxDepth, res);
    dfsDeepestLeft(node->right, depth + 1, false, maxDepth, res);
}

int deepestLeftLeaf(struct TreeNode* root) {
    int maxDepth = -1, res = -1;
    dfsDeepestLeft(root, 0, false, &maxDepth, &res);
    return res;
}