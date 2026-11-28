#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int dfs(TreeNode* node, int maxVal) {
        if (!node) return 0;
        int good = node->val >= maxVal ? 1 : 0;
        int newMax = std::max(maxVal, node->val);
        return good + dfs(node->left, newMax) + dfs(node->right, newMax);
    }
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};