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
        auto [lRob, lSkip] = dfs(node->left);
        auto [rRob, rSkip] = dfs(node->right);

        int robCur = node->val + lSkip + rSkip;
        int skipCur = std::max(lRob, lSkip) + std::max(rRob, rSkip);
        return {robCur, skipCur};
    }
public:
    int rob(TreeNode* root) {
        auto [r, s] = dfs(root);
        return std::max(r, s);
    }
};