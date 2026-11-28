struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int dfs(TreeNode* node) {
        if (!node) return 0;
        int lSum = dfs(node->left);
        int rSum = dfs(node->right);
        int oldVal = node->val;
        node->val = lSum + rSum;
        return node->val + oldVal;
    }
public:
    TreeNode* convertToDescendantSum(TreeNode* root) {
        dfs(root);
        return root;
    }
};