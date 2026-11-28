struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int dfs(TreeNode* node, int level) {
        if (!node) return 0;
        int cur = level % 2 == 1 ? node->val : 0;
        return cur + dfs(node->left, level + 1) + dfs(node->right, level + 1);
    }
public:
    int sumOddLevels(TreeNode* root) {
        return dfs(root, 1);
    }
};