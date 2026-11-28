#include <vector>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    std::vector<std::vector<int>> res;

    int dfs(TreeNode* node) {
        if (!node) return -1;
        int height = 1 + std::max(dfs(node->left), dfs(node->right));
        if (height == (int)res.size()) res.push_back({});
        res[height].push_back(node->val);
        return height;
    }
public:
    std::vector<std::vector<int>> findLeaves(TreeNode* root) {
        res.clear();
        dfs(root);
        return res;
    }
};