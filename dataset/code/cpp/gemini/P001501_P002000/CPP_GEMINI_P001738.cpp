#include <algorithm>
#include <tuple>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int maxSize = 0;

    std::tuple<bool, bool, int, int> dfs(TreeNode* node) {
        if (!node) return {true, true, 0, 0};

        auto [lComp, lPerf, lH, lSize] = dfs(node->left);
        auto [rComp, rPerf, rH, rSize] = dfs(node->right);

        int curSize = lSize + rSize + 1;

        if (lPerf && rComp && lH == rH) {
            maxSize = std::max(maxSize, curSize);
            return {true, rPerf, lH + 1, curSize};
        }

        if (lComp && rPerf && lH == rH + 1) {
            maxSize = std::max(maxSize, curSize);
            return {true, false, lH + 1, curSize};
        }

        return {false, false, 0, 0};
    }
public:
    int largestCompleteSubtree(TreeNode* root) {
        maxSize = 0;
        dfs(root);
        return maxSize;
    }
};