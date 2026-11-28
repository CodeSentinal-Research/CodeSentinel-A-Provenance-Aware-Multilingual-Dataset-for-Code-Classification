#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    std::vector<TreeNode*> splitBST(TreeNode* root, int target) {
        if (!root) return {nullptr, nullptr};

        if (root->val <= target) {
            auto res = splitBST(root->right, target);
            root->right = res[0];
            return {root, res[1]};
        } else {
            auto res = splitBST(root->left, target);
            root->left = res[1];
            return {res[0], root};
        }
    }
};