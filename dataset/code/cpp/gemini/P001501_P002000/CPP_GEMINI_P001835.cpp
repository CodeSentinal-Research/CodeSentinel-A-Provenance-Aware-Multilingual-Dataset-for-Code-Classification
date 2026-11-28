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

    std::pair<bool, int> dfs(TreeNode* node, int low, int high) {
        if (!node) return {true, 0};
        if (low == high) return {false, 0};

        auto [lFree, lSz] = dfs(node->left, low, node->val - 1);
        auto [rFree, rSz] = dfs(node->right, node->val + 1, high);

        if (lFree && rFree) {
            int curSize = lSz + rSz + 1;
            maxSize = std::max(maxSize, curSize);
            return {true, curSize};
        }

        return {false, 0};
    }
public:
    int largestDeadEndFreeSubtree(TreeNode* root) {
        maxSize = 0;
        dfs(root, 1, INT_MAX);
        return maxSize;
    }
};