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

    std::tuple<bool, bool, bool, int, int, int, int> dfs(TreeNode* node) {
        if (!node) return {true, true, true, 0, 0, INT_MAX, INT_MIN};

        auto [lBst, lComp, lPerf, lH, lSz, lMin, lMax] = dfs(node->left);
        auto [rBst, rComp, rPerf, rH, rSz, rMin, rMax] = dfs(node->right);

        bool isBST = lBst && rBst && lMax < node->val && node->val < rMin;
        int curSz = lSz + rSz + 1;
        int minV = std::min(lMin, node->val);
        int maxV = std::max(rMax, node->val);

        if (isBST) {
            if (lPerf && rComp && lH == rH) {
                maxSize = std::max(maxSize, curSz);
                return {true, true, rPerf, lH + 1, curSz, minV, maxV};
            }
            if (lComp && rPerf && lH == rH + 1) {
                maxSize = std::max(maxSize, curSz);
                return {true, true, false, lH + 1, curSz, minV, maxV};
            }
        }

        return {false, false, false, 0, 0, 0, 0};
    }
public:
    int largestCompleteBSTSubtree(TreeNode* root) {
        maxSize = 0;
        dfs(root);
        return maxSize;
    }
};