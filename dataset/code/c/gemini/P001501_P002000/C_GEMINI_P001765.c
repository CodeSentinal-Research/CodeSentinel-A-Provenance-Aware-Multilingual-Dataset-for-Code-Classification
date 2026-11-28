#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool dfsSameLength(struct TreeNode* node, int depth, int* leafDepth) {
    if (node == NULL) return true;
    if (node->left == NULL && node->right == NULL) {
        if (*leafDepth == -1) {
            *leafDepth = depth;
            return true;
        }
        return *leafDepth == depth;
    }
    return dfsSameLength(node->left, depth + 1, leafDepth) && dfsSameLength(node->right, depth + 1, leafDepth);
}

bool allPathsSameLength(struct TreeNode* root) {
    int leafDepth = -1;
    return dfsSameLength(root, 0, &leafDepth);
}