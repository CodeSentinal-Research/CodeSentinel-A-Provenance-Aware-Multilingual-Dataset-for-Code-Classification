struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int leafDepth = -1;

    bool dfs(TreeNode* node, int depth) {
        if (!node) return true;
        if (!node->left && !node->right) {
            if (leafDepth == -1) {
                leafDepth = depth;
                return true;
            }
            return leafDepth == depth;
        }
        return dfs(node->left, depth + 1) && dfs(node->right, depth + 1);
    }
public:
    bool allPathsSameLength(TreeNode* root) {
        leafDepth = -1;
        return dfs(root, 0);
    }
};