#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Performs search to locate target element within the given collection.
int maxSearchCost(struct TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + MAX(maxSearchCost(root->left), maxSearchCost(root->right));
}