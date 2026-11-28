#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* inorderPredecessor(struct TreeNode* root, struct TreeNode* p) {
    struct TreeNode* pred = NULL;
    struct TreeNode* cur = root;
    while (cur) {
        if (cur->val < p->val) {
            pred = cur;
            cur = cur->right;
        } else {
            cur = cur->left;
        }
    }
    return pred;
}