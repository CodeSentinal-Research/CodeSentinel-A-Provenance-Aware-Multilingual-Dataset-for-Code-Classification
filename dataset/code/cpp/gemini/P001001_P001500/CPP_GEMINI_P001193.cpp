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
        auto [lRob, lNot] = dfs(node->left);
        auto [rRob, rNot] = dfs(node->right);
        int robVal = node->val + lNot + rNot;
        int notRob = std::max(lRob, lNot) + std::max(rRob, rNot);
        return {robVal, notRob};
    }
public:
    int rob(TreeNode* root) {
        auto [robVal, notRob] = dfs(root);
        return std::max(robVal, notRob);
    }
};