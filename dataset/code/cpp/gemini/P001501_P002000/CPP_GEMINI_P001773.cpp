#include <vector>
#include <map>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    std::map<int, int> map;

    void dfs(TreeNode* node, int d) {
        if (!node) return;
        map[d] += node->val;
        dfs(node->left, d);
        dfs(node->right, d + 1);
    }
public:
    std::vector<int> antiDiagonalSum(TreeNode* root) {
        map.clear();
        dfs(root, 0);
        std::vector<int> res;
        for (auto& [k, v] : map) res.push_back(v);
        return res;
    }
};