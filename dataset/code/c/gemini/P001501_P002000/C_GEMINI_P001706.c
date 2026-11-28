#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int countNodes(struct TreeNode* root) {
    if (root == NULL) return 0;
    int lDepth = 0, rDepth = 0;
    struct TreeNode *l = root, *r = root;

    while (l) {
        lDepth++;
        l = l->left;
    }
    while (r) {
        rDepth++;
        r = r->right;
    }

    if (lDepth == rDepth) return (1 << lDepth) - 1;

    return 1 + countNodes(root->left) + countNodes(root->right);
}