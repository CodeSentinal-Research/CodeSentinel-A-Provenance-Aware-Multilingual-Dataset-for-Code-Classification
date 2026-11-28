#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int dfsPerfect(struct TreeNode* node, int* maxSize) {
    if (node == NULL) return 0;
    int l = dfsPerfect(node->left, maxSize);
    int r = dfsPerfect(node->right, maxSize);

    if (l != -1 && r != -1 && l == r) {
        int depth = l + 1;
        int size = (1 << depth) - 1;
        *maxSize = MAX(*maxSize, size);
        return depth;
    }
    return -1;
}

int largestPerfectSubtree(struct TreeNode* root) {
    int maxSize = 0;
    dfsPerfect(root, &maxSize);
    return maxSize;
}