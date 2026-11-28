#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int maxPath = 0;

    int dfs(TreeNode* node) {
        if (!node) return 0;
        int lLen = dfs(node->left);
        int rLen = dfs(node->right);

        int lArrow = (node->left && node->left->val == node->val) ? lLen + 1 : 0;
        int rArrow = (node->right && node->right->val == node->val) ? rLen + 1 : 0;

        maxPath = std::max(maxPath, lArrow + rArrow);
        return std::max(lArrow, rArrow);
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        maxPath = 0;
        dfs(root);
        return maxPath;
    }
};