#include <unordered_map>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    std::unordered_map<int, int> heights;

    int dfs(TreeNode* node) {
        if (!node) return -1;
        int h = 1 + std::max(dfs(node->left), dfs(node->right));
        heights[node->val] = h;
        return h;
    }
public:
    std::unordered_map<int, int> nodeHeights(TreeNode* root) {
        heights.clear();
        dfs(root);
        return heights;
    }
};