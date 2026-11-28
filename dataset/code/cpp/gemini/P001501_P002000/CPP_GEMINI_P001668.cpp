#include <utility>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    std::pair<int, TreeNode*> dfs(TreeNode* node) {
        if (!node) return {0, nullptr};
        auto [lDepth, lNode] = dfs(node->left);
        auto [rDepth, rNode] = dfs(node->right);
        if (lDepth == rDepth) return {lDepth + 1, node};
        if (lDepth > rDepth) return {lDepth + 1, lNode};
        return {rDepth + 1, rNode};
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }
};