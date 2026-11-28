#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int ceilBST(struct TreeNode* root, int key) {
    int ceilVal = -1;
    struct TreeNode* cur = root;

    while (cur) {
        if (cur->val == key) {
            return cur->val;
        } else if (cur->val > key) {
            ceilVal = cur->val;
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
    return ceilVal;
}