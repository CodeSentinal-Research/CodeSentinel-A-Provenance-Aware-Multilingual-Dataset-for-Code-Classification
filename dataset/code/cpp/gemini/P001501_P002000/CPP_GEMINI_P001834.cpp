#include <climits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    bool dfs(TreeNode* node, int low, int high) {
        if (!node) return false;
        if (low == high) return true;
        return dfs(node->left, low, node->val - 1) || dfs(node->right, node->val + 1, high);
    }
public:
    bool isDeadEnd(TreeNode* root) {
        return dfs(root, 1, INT_MAX);
    }
};