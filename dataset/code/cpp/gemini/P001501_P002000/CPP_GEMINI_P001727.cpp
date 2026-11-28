#include <vector>
#include <string>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    void dfs(TreeNode* node, std::string path, std::vector<std::string>& res) {
        if (!node) return;
        path += std::to_string(node->val);
        if (!node->left && !node->right) {
            res.push_back(path);
        } else {
            dfs(node->left, path + "->", res);
            dfs(node->right, path + "->", res);
        }
    }
public:
    std::vector<std::string> binaryTreePaths(TreeNode* root) {
        std::vector<std::string> res;
        dfs(root, "", res);
        return res;
    }
};