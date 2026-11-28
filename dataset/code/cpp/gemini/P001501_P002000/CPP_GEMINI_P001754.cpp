struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int maxDepth = -1, res = 0;

    void dfs(TreeNode* node, int depth) {
        if (!node) return;
        if (depth > maxDepth) {
            maxDepth = depth;
            res = node->val;
        }
        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        maxDepth = -1;
        res = root->val;
        dfs(root, 0);
        return res;
    }
};