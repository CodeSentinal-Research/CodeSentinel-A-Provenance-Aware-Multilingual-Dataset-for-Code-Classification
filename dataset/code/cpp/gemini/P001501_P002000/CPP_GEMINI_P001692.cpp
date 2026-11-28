#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int maxLen = 0;

    void dfs(TreeNode* node, TreeNode* parent, int length) {
        if (!node) return;
        if (parent && node->val == parent->val + 1) {
            length++;
        } else {
            length = 1;
        }
        maxLen = std::max(maxLen, length);
        dfs(node->left, node, length);
        dfs(node->right, node, length);
    }
public:
    int longestConsecutive(TreeNode* root) {
        maxLen = 0;
        dfs(root, nullptr, 0);
        return maxLen;
    }
};