#include <algorithm>
#include <climits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int minSum = INT_MAX;

    int dfs(TreeNode* node) {
        if (!node) return 0;
        int curSum = node->val + dfs(node->left) + dfs(node->right);
        minSum = std::min(minSum, curSum);
        return curSum;
    }
public:
    int minSubtreeSum(TreeNode* root) {
        minSum = INT_MAX;
        dfs(root);
        return minSum;
    }
};