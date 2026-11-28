#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void flatten(struct TreeNode* root) {
    struct TreeNode* cur = root;
    while (cur) {
        if (cur->left) {
            struct TreeNode* prev = cur->left;
            while (prev->right) prev = prev->right;
            prev->right = cur->right;
            cur->right = cur->left;
            cur->left = NULL;
        }
        cur = cur->right;
    }
}