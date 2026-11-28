#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int dfs(TreeNode* node, int minVal, int maxVal) {
        if (!node) return maxVal - minVal;
        minVal = std::min(minVal, node->val);
        maxVal = std::max(maxVal, node->val);
        return std::max(dfs(node->left, minVal, maxVal), dfs(node->right, minVal, maxVal));
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        if (!root) return 0;
        return dfs(root, root->val, root->val);
    }
};