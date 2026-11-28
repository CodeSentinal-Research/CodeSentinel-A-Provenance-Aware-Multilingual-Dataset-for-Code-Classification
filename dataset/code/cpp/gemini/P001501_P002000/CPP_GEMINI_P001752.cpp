#include <unordered_map>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    std::unordered_map<int, int> map;

    void dfs(TreeNode* node, int depth) {
        if (!node) return;
        map[node->val] = depth;
        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
    }
public:
    std::unordered_map<int, int> countAncestors(TreeNode* root) {
        map.clear();
        dfs(root, 0);
        return map;
    }
};