#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int maxLen = 0;

    void dfs(TreeNode* node, bool isLeft, int length) {
        if (!node) return;
        maxLen = std::max(maxLen, length);
        if (isLeft) {
            dfs(node->left, true, 1);
            dfs(node->right, false, length + 1);
        } else {
            dfs(node->left, true, length + 1);
            dfs(node->right, false, 1);
        }
    }
public:
    int longestZigZag(TreeNode* root) {
        if (!root) return 0;
        maxLen = 0;
        dfs(root->left, true, 1);
        dfs(root->right, false, 1);
        return maxLen;
    }
};