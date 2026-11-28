#include <unordered_map>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    std::unordered_map<int, int> depths;

    void dfs(TreeNode* node, int d) {
        if (!node) return;
        depths[node->val] = d;
        dfs(node->left, d + 1);
        dfs(node->right, d + 1);
    }
public:
    std::unordered_map<int, int> nodeDepths(TreeNode* root) {
        depths.clear();
        dfs(root, 0);
        return depths;
    }
};