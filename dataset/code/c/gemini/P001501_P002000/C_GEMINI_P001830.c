#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int smallestGreater(struct TreeNode* root, int key) {
    int ans = -1;
    struct TreeNode* cur = root;

    while (cur) {
        if (cur->val > key) {
            ans = cur->val;
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
    return ans;
}