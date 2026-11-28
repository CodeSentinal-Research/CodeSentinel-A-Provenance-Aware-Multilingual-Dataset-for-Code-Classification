#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int maxLen = 0;

    void dfs(TreeNode* node, int parentVal, bool hasParent, int curLen) {
        if (!node) return;
        if (!hasParent || node->val > parentVal) {
            curLen++;
        } else {
            curLen = 1;
        }
        maxLen = std::max(maxLen, curLen);
        dfs(node->left, node->val, true, curLen);
        dfs(node->right, node->val, true, curLen);
    }
public:
    int longestIncreasingPath(TreeNode* root) {
        maxLen = 0;
        dfs(root, 0, false, 0);
        return maxLen;
    }
};