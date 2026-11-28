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
    int maxBSTSize = 0;
    int bestDiameter = 0;

    std::tuple<bool, int, int, int, int, int> dfs(TreeNode* node) {
        if (!node) return {true, 0, 0, 0, INT_MAX, INT_MIN};

        auto [lBst, lSz, lH, lD, lMin, lMax] = dfs(node->left);
        auto [rBst, rSz, rH, rD, rMin, rMax] = dfs(node->right);

        if (lBst && rBst && lMax < node->val && node->val < rMin) {
            int curSz = lSz + rSz + 1;
            int curH = 1 + std::max(lH, rH);
            int curD = std::max(lH + rH, std::max(lD, rD));

            if (curSz > maxBSTSize) {
                maxBSTSize = curSz;
                bestDiameter = curD;
            }

            return {true, curSz, curH, curD, std::min(lMin, node->val), std::max(rMax, node->val)};
        }

        return {false, 0, 0, 0, 0, 0};
    }
public:
    int diameterOfLargestBST(TreeNode* root) {
        maxBSTSize = 0;
        bestDiameter = 0;
        dfs(root);
        return bestDiameter;
    }
};