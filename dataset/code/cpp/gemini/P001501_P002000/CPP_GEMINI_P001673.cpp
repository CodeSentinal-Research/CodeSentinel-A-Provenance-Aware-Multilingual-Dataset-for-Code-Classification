#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    void dfs(TreeNode* node, int depth, std::vector<int>& res) {
        if (!node) return;
        if (depth == (int)res.size()) res.push_back(node->val);
        dfs(node->left, depth + 1, res);
        dfs(node->right, depth + 1, res);
    }
public:
    std::vector<int> leftSideView(TreeNode* root) {
        std::vector<int> res;
        dfs(root, 0, res);
        return res;
    }
};