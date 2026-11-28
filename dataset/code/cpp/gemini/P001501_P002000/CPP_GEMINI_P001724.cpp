#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int minPathSum(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return root->val;
        if (!root->left) return root->val + minPathSum(root->right);
        if (!root->right) return root->val + minPathSum(root->left);
        return root->val + std::min(minPathSum(root->left), minPathSum(root->right));
    }
};