#include <climits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int minDepth = INT_MAX;
    int res = -1;

    void dfs(TreeNode* node, int depth) {
        if (!node) return;
        if (!node->left && !node->right) {
            if (depth < minDepth) {
                minDepth = depth;
                res = node->val;
            }
            return;
        }
        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
    }
public:
    int lowestLeaf(TreeNode* root) {
        minDepth = INT_MAX;
        res = -1;
        dfs(root, 1);
        return res;
    }
};