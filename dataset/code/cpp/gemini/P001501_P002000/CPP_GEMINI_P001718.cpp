struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int dfs(TreeNode* node, int edges, int k) {
        if (!node) return 0;
        if (!node->left && !node->right) return edges == k ? 1 : 0;
        return dfs(node->left, edges + 1, k) + dfs(node->right, edges + 1, k);
    }
public:
    int countPathsKEdges(TreeNode* root, int k) {
        return dfs(root, 0, k);
    }
};