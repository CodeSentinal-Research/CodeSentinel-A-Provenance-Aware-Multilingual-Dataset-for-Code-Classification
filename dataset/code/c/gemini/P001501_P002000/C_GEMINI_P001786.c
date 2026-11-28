#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* searchBST(struct TreeNode* root, int val) {
    struct TreeNode* cur = root;
    while (cur && cur->val != val) {
        cur = val < cur->val ? cur->left : cur->right;
    }
    return cur;
}