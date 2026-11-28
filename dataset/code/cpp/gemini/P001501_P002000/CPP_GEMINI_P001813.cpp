#include <cmath>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int closest = root->val;
        TreeNode* cur = root;

        while (cur) {
            if (std::abs(cur->val - target) < std::abs(closest - target) ||
                (std::abs(cur->val - target) == std::abs(closest - target) && cur->val < closest)) {
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
};