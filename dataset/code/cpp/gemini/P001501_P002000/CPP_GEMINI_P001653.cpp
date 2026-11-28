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
    int gain(TreeNode* node) {
        if (!node) return 0;
        int leftGain = std::max(0, gain(node->left));
        int rightGain = std::max(0, gain(node->right));
        maxSum = std::max(maxSum, node->val + leftGain + rightGain);
        return node->val + std::max(leftGain, rightGain);
    }
public:
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        gain(root);
        return maxSum;
    }
};