#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isMirrorSub(struct TreeNode* t1, struct TreeNode* t2) {
    if (t1 == NULL && t2 == NULL) return true;
    if (t1 == NULL || t2 == NULL || t1->val != t2->val) return false;
    return isMirrorSub(t1->left, t2->right) && isMirrorSub(t1->right, t2->left);
}

void dfsCountSym(struct TreeNode* node, int* count) {
    if (node == NULL) return;
    if (isMirrorSub(node->left, node->right)) (*count)++;
    dfsCountSym(node->left, count);
    dfsCountSym(node->right, count);
}

int countSymmetricSubtrees(struct TreeNode* root) {
    int count = 0;
    dfsCountSym(root, &count);
    return count;
}