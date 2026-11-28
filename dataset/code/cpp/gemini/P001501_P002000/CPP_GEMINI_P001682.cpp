struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int leafLevel = -1;
    bool dfs(TreeNode* node, int level) {
        if (!node) return true;
        if (!node->left && !node->right) {
            if (leafLevel == -1) {
                leafLevel = level;
                return true;
            }
            return leafLevel == level;
        }
        return dfs(node->left, level + 1) && dfs(node->right, level + 1);
    }
public:
    bool checkLeavesSameLevel(TreeNode* root) {
        leafLevel = -1;
        return dfs(root, 0);
    }
};