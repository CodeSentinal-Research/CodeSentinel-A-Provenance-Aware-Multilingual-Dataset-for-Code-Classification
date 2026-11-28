#include <algorithm>
#include <utility>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    std::pair<int, int> dfs(TreeNode* node) {
        if (!node) return {0, 0};
        auto [lIncl, lExcl] = dfs(node->left);
        auto [rIncl, rExcl] = dfs(node->right);

        int incl = 1 + lExcl + rExcl;
        int excl = std::max(lIncl, lExcl) + std::max(rIncl, rExcl);
        return {incl, excl};
    }
public:
    int maxIndependentSet(TreeNode* root) {
        auto [incl, excl] = dfs(root);
        return std::max(incl, excl);
    }
};