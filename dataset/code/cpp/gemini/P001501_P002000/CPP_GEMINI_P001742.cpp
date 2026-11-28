#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    void dfs(TreeNode* node, std::vector<int>& res) {
        if (!node) return;
        if (!node->left && !node->right) {
            res.push_back(node->val);
            return;
        }
        dfs(node->right, res);
        dfs(node->left, res);
    }
public:
    std::vector<int> getLeavesRightToLeft(TreeNode* root) {
        std::vector<int> res;
        dfs(root, res);
        return res;
    }
};