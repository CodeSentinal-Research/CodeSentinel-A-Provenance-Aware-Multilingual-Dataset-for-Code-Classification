struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int maxDepth = -1;
    int res = -1;

    void dfs(TreeNode* node, int depth, bool isLeft) {
        if (!node) return;
        if (isLeft && !node->left && !node->right) {
            if (depth > maxDepth) {
                maxDepth = depth;
                res = node->val;
            }
        }
        dfs(node->left, depth + 1, true);
        dfs(node->right, depth + 1, false);
    }
public:
    int deepestLeftLeaf(TreeNode* root) {
        maxDepth = -1;
        res = -1;
        dfs(root, 0, false);
        return res;
    }
};