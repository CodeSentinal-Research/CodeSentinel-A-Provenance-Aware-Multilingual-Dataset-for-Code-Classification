#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return root->val;
        if (!root->left) return root->val + maxPathSum(root->right);
        if (!root->right) return root->val + maxPathSum(root->left);
        return root->val + std::max(maxPathSum(root->left), maxPathSum(root->right));
    }
};