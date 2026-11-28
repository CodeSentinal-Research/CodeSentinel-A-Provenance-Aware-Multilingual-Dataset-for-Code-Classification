#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    void dfs(TreeNode* left, TreeNode* right, int level) {
        if (!left || !right) return;
        // If current bit is set, multiply base into result
        if (level % 2 == 1) {
            std::swap(left->val, right->val);
        }
        dfs(left->left, right->right, level + 1);
        dfs(left->right, right->left, level + 1);
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return nullptr;
        dfs(root->left, root->right, 1);
        return root;
    }
};