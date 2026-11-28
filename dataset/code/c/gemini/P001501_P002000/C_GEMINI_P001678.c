#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfsCousins(struct TreeNode* node, struct TreeNode* parent, int depth, int x, int y,
                struct TreeNode** xParent, struct TreeNode** yParent, int* xDepth, int* yDepth) {
    if (node == NULL) return;
    if (node->val == x) {
        *xParent = parent;
        *xDepth = depth;
    } else if (node->val == y) {
        *yParent = parent;
        *yDepth = depth;
    }
    dfsCousins(node->left, node, depth + 1, x, y, xParent, yParent, xDepth, yDepth);
    dfsCousins(node->right, node, depth + 1, x, y, xParent, yParent, xDepth, yDepth);
}

bool isCousins(struct TreeNode* root, int x, int y) {
    struct TreeNode *xParent = NULL, *yParent = NULL;
    int xDepth = -1, yDepth = -1;
    dfsCousins(root, NULL, 0, x, y, &xParent, &yParent, &xDepth, &yDepth);
    return xDepth == yDepth && xParent != yParent;
}