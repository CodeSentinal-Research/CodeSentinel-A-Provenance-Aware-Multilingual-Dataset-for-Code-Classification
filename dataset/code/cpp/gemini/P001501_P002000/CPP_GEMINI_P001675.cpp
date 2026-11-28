#include <vector>
#include <map>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    std::map<int, std::vector<int>> diagMap;
    void dfs(TreeNode* node, int d) {
        if (!node) return;
        diagMap[d].push_back(node->val);
        dfs(node->left, d + 1);
        dfs(node->right, d);
    }
public:
    std::vector<int> diagonalTraversal(TreeNode* root) {
        diagMap.clear();
        dfs(root, 0);
        std::vector<int> res;
        for (auto& [d, vals] : diagMap) {
            res.insert(res.end(), vals.begin(), vals.end());
        }
        return res;
    }
};