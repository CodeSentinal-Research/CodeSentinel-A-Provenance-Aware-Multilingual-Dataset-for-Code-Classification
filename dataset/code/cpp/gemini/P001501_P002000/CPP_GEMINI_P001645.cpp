#include <vector>
#include <map>
#include <set>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    std::map<int, std::map<int, std::multiset<int>>> nodes;
    void dfs(TreeNode* node, int col, int row) {
        if (!node) return;
        nodes[col][row].insert(node->val);
        dfs(node->left, col - 1, row + 1);
        dfs(node->right, col + 1, row + 1);
    }
public:
    std::vector<std::vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        std::vector<std::vector<int>> res;

        for (auto& [col, row_map] : nodes) {
            std::vector<int> col_vals;
            for (auto& [row, multiset_vals] : row_map) {
                col_vals.insert(col_vals.end(), multiset_vals.begin(), multiset_vals.end());
            }
            res.push_back(col_vals);
        }
        return res;
    }
};