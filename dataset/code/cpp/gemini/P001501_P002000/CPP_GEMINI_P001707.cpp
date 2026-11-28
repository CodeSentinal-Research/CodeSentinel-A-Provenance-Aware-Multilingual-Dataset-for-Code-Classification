struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    void dfs(TreeNode* node, int val, int depth, int curDepth) {
        if (!node) return;
        if (curDepth == depth - 1) {
            node->left = new TreeNode(val, node->left, nullptr);
            node->right = new TreeNode(val, nullptr, node->right);
            return;
        }
        dfs(node->left, val, depth, curDepth + 1);
        dfs(node->right, val, depth, curDepth + 1);
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) return new TreeNode(val, root, nullptr);
        dfs(root, val, depth, 1);
        return root;
    }
};