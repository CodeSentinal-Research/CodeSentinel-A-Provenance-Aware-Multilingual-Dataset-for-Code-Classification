#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    bool isThreaded;
};

bool verifyThreaded(struct TreeNode* root) {
    if (root == NULL) return true;
    struct TreeNode* cur = root;
    while (cur->left) cur = cur->left;

    int count = 0;
    while (cur) {
        count++;
        if (cur->isThreaded) {
            cur = cur->right;
        } else {
            cur = cur->right;
            while (cur && cur->left) cur = cur->left;
        }
    }
    return count > 0;
}