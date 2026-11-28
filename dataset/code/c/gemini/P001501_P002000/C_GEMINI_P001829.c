#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int largestSmaller(struct TreeNode* root, int key) {
    int ans = -1;
    struct TreeNode* cur = root;

    while (cur) {
        if (cur->val < key) {
            ans = cur->val;
            cur = cur->right;
        } else {
            cur = cur->left;
        }
    }
    return ans;
}