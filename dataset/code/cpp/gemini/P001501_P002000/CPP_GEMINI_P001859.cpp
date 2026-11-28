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

    std::tuple<bool, bool, int, int, int> dfs(TreeNode* node) {
        if (!node) return {true, true, 0, INT_MAX, INT_MIN};

        auto [lBst, lPerf, lH, lMin, lMax] = dfs(node->left);
        auto [rBst, rPerf, rH, rMin, rMax] = dfs(node->right);

        bool isBST = lBst && rBst && lMax < node->val && node->val < rMin;
        int minV = std::min(lMin, node->val);
        int maxV = std::max(rMax, node->val);

        if (isBST && lPerf && rPerf && lH == rH) {
            int curH = lH + 1;
            int size = (1 << curH) - 1;
            maxSize = std::max(maxSize, size);
            return {true, true, curH, minV, maxV};
        }

        return {false, false, 0, 0, 0};
    }
public:
    int largestPerfectBSTSubtree(TreeNode* root) {
        maxSize = 0;
        dfs(root);
        return maxSize;
    }
};