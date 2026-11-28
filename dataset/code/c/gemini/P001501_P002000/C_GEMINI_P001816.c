#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int floorBST(struct TreeNode* root, int key) {
    int floorVal = -1;
    struct TreeNode* cur = root;

    while (cur) {
        if (cur->val == key) {
            return cur->val;
        } else if (cur->val < key) {
            floorVal = cur->val;
            cur = cur->right;
        } else {
            cur = cur->left;
        }
    }
    return floorVal;
}