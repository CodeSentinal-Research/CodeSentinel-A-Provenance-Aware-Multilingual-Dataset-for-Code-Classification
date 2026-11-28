struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    TreeNode *xParent = nullptr, *yParent = nullptr;
    int xDepth = -1, yDepth = -1;

    void dfs(TreeNode* node, TreeNode* parent, int depth, int x, int y) {
        if (!node) return;
        if (node->val == x) {
            xParent = parent;
            xDepth = depth;
        } else if (node->val == y) {
            yParent = parent;
            yDepth = depth;
        }
        dfs(node->left, node, depth + 1, x, y);
        dfs(node->right, node, depth + 1, x, y);
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, nullptr, 0, x, y);
        return xDepth == yDepth && xParent != yParent;
    }
};