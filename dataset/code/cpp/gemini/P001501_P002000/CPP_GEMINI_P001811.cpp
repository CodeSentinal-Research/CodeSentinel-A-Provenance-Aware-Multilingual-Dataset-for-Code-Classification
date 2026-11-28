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
    int maxSize = 0;

    std::tuple<bool, int, int, int> dfs(TreeNode* node) {
        if (!node) return {true, 0, INT_MAX, INT_MIN};

        auto [lBst, lSize, lMin, lMax] = dfs(node->left);
        auto [rBst, rSize, rMin, rMax] = dfs(node->right);

        if (lBst && rBst && lMax < node->val && node->val < rMin) {
            int curSize = lSize + rSize + 1;
            maxSize = std::max(maxSize, curSize);
            return {true, curSize, std::min(lMin, node->val), std::max(rMax, node->val)};
        }

        return {false, 0, 0, 0};
    }
public:
    int largestBSTSubtree(TreeNode* root) {
        maxSize = 0;
        dfs(root);
        return maxSize;
    }
};