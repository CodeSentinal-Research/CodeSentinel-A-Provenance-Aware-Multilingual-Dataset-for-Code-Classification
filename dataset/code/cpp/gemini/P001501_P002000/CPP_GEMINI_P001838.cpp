#include <unordered_set>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    std::unordered_set<int> seen;

    bool dfs(TreeNode* node, int k) {
        if (!node) return false;
        if (seen.count(k - node->val)) return true;
        seen.insert(node->val);
        return dfs(node->left, k) || dfs(node->right, k);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        seen.clear();
        return dfs(root, k);
    }
};