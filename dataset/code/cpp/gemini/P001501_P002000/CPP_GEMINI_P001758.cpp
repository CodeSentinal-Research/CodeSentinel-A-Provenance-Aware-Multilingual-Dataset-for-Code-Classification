#include <unordered_set>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    std::unordered_set<int> seen;

    bool dfs(TreeNode* node) {
        if (!node) return false;
        if (seen.count(node->val)) return true;
        seen.insert(node->val);
        return dfs(node->left) || dfs(node->right);
    }
public:
    bool containsDuplicate(TreeNode* root) {
        seen.clear();
        return dfs(root);
    }
};