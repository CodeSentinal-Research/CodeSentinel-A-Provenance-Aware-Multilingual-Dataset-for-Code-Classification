#include <algorithm>
#include <climits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int maxSum = INT_MIN;

    int dfs(TreeNode* node) {
        if (!node) return 0;
        int curSum = node->val + dfs(node->left) + dfs(node->right);
        maxSum = std::max(maxSum, curSum);
        return curSum;
    }
public:
    int maxSubtreeSum(TreeNode* root) {
        maxSum = INT_MIN;
        dfs(root);
        return maxSum;
    }
};