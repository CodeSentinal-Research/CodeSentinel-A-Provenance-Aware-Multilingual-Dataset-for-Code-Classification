#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* inorderSuccessor(struct TreeNode* root, struct TreeNode* p) {
    struct TreeNode* succ = NULL;
    struct TreeNode* cur = root;
    while (cur) {
        if (cur->val > p->val) {
            succ = cur;
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
    return succ;
}