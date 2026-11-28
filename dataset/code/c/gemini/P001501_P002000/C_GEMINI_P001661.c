#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isFoldableMirror(struct TreeNode* t1, struct TreeNode* t2) {
    if (t1 == NULL && t2 == NULL) return true;
    if (t1 == NULL || t2 == NULL) return false;
    return isFoldableMirror(t1->left, t2->right) && isFoldableMirror(t1->right, t2->left);
}

bool isFoldable(struct TreeNode* root) {
    if (root == NULL) return true;
    return isFoldableMirror(root->left, root->right);
}