#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isMirrorSame(struct TreeNode* t1, struct TreeNode* t2) {
    if (t1 == NULL && t2 == NULL) return true;
    if (t1 == NULL || t2 == NULL || t1->val != t2->val) return false;
    return isMirrorSame(t1->left, t2->right) && isMirrorSame(t1->right, t2->left);
}

bool isSymmetric(struct TreeNode* root) {
    return isMirrorSame(root, root);
}