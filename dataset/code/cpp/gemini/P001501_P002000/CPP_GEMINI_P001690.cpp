#include <algorithm>
#include <climits>
#include <tuple>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int maxSum = 0;

    std::tuple<bool, int, int, int> dfs(TreeNode* node) {
        if (!node) return {true, INT_MAX, INT_MIN, 0};

        auto [lBst, lMin, lMax, lSum] = dfs(node->left);
        auto [rBst, rMin, rMax, rSum] = dfs(node->right);

        if (lBst && rBst && lMax < node->val && node->val < rMin) {
            int curSum = lSum + rSum + node->val;
            maxSum = std::max(maxSum, curSum);
            return {true, std::min(lMin, node->val), std::max(rMax, node->val), curSum};
        }

        return {false, 0, 0, 0};
    }
public:
    int maxSumBST(TreeNode* root) {
        maxSum = 0;
        dfs(root);
        return maxSum;
    }
};