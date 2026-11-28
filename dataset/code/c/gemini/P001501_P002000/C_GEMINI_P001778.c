#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfsMonotonic(struct TreeNode* node, int parentVal, bool hasParent, bool isInc, bool isDec, int* count) {
    if (node == NULL) return;
    if (hasParent) {
        if (node->val < parentVal) isInc = false;
        if (node->val > parentVal) isDec = false;
    }
    if (node->left == NULL && node->right == NULL) {
        if (isInc || isDec) (*count)++;
        return;
    }
    dfsMonotonic(node->left, node->val, true, isInc, isDec, count);
    dfsMonotonic(node->right, node->val, true, isInc, isDec, count);
}

int countMonotonicPaths(struct TreeNode* root) {
    int count = 0;
    dfsMonotonic(root, 0, false, true, true, &count);
    return count;
}