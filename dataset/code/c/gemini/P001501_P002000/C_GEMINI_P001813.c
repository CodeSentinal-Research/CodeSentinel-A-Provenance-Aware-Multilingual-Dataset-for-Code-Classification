#include <stdlib.h>
#include <math.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int closestValue(struct TreeNode* root, double target) {
    int closest = root->val;
    struct TreeNode* cur = root;

    while (cur) {
        if (fabs(cur->val - target) < fabs(closest - target) ||
            (fabs(cur->val - target) == fabs(closest - target) && cur->val < closest)) {
            closest = cur->val;
        }

        if (target < cur->val) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
    return closest;
}