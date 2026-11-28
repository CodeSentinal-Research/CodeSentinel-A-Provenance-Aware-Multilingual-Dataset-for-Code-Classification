#include <stdlib.h>
#include <stdbool.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isMirrorSym(struct TreeNode* t1, struct TreeNode* t2) {
    if (t1 == NULL && t2 == NULL) return true;
    if (t1 == NULL || t2 == NULL || t1->val != t2->val) return false;
    return isMirrorSym(t1->left, t2->right) && isMirrorSym(t1->right, t2->left);
}

int countNodesSub(struct TreeNode* node) {
    if (node == NULL) return 0;
    return 1 + countNodesSub(node->left) + countNodesSub(node->right);
}

void dfsLargestSym(struct TreeNode* node, int* maxSize) {
    if (node == NULL) return;
    if (isMirrorSym(node->left, node->right)) {
        int sz = countNodesSub(node);
        *maxSize = MAX(*maxSize, sz);
    }
    dfsLargestSym(node->left, maxSize);
    dfsLargestSym(node->right, maxSize);
}

int largestSymmetricSubtree(struct TreeNode* root) {
    int maxSize = 0;
    dfsLargestSym(root, &maxSize);
    return maxSize;
}