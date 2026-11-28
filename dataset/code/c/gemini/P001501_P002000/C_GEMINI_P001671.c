#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* res = (int*)malloc(10005 * sizeof(int));
    int idx = 0;
    struct TreeNode* cur = root;

    while (cur) {
        if (!cur->left) {
            res[idx++] = cur->val;
            cur = cur->right;
        } else {
            struct TreeNode* prev = cur->left;
            while (prev->right && prev->right != cur) {
                prev = prev->right;
            }
            if (!prev->right) {
                prev->right = cur;
                cur = cur->left;
            } else {
                prev->right = NULL;
                res[idx++] = cur->val;
                cur = cur->right;
            }
        }
    }
    *returnSize = idx;
    return res;
}