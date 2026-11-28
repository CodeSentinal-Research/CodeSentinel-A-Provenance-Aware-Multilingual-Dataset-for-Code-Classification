#include <string>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    std::string ans = "~";

    void dfs(TreeNode* node, std::string path) {
        if (!node) return;
        path = (char)('a' + node->val) + path;
        if (!node->left && !node->right) {
            ans = std::min(ans, path);
        }
        dfs(node->left, path);
        dfs(node->right, path);
    }
public:
    std::string smallestFromLeaf(TreeNode* root) {
        ans = "~";
        dfs(root, "");
        return ans;
    }
};