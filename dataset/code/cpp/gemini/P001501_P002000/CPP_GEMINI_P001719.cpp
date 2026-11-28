#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    std::vector<int> longest;

    void dfs(TreeNode* node, std::vector<int>& path) {
        if (!node) return;
        path.push_back(node->val);
        if (!node->left && !node->right) {
            if (path.size() > longest.size()) {
                longest = path;
            }
        } else {
            dfs(node->left, path);
            dfs(node->right, path);
        }
        path.pop_back();
    }
public:
    std::vector<int> longestPath(TreeNode* root) {
        longest.clear();
        std::vector<int> path;
        dfs(root, path);
        return longest;
    }
};