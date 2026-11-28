struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int ans = 0;

    int dfs(TreeNode* node, int k) {
        if (!node) return 0;
        int desc = dfs(node->left, k) + dfs(node->right, k);
        if (desc == k) ans++;
        return desc + 1;
    }
public:
    int countNodesWithKDescendants(TreeNode* root, int k) {
        ans = 0;
        dfs(root, k);
        return ans;
    }
};