#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool dfsSameLeaf(struct TreeNode* node, int level, int* leafLevel) {
    if (node == NULL) return true;
    if (node->left == NULL && node->right == NULL) {
        if (*leafLevel == -1) {
            *leafLevel = level;
            return true;
        }
        return *leafLevel == level;
    }
    return dfsSameLeaf(node->left, level + 1, leafLevel) && dfsSameLeaf(node->right, level + 1, leafLevel);
}

bool checkLeavesSameLevel(struct TreeNode* root) {
    int leafLevel = -1;
    return dfsSameLeaf(root, 0, &leafLevel);
}