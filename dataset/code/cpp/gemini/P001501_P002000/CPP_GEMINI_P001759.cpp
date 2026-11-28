#include <vector>
#include <unordered_map>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    std::unordered_map<int, int> count;

    void dfs(TreeNode* node) {
        if (!node) return;
        count[node->val]++;
        dfs(node->left);
        dfs(node->right);
    }
public:
    std::vector<int> findMode(TreeNode* root) {
        count.clear();
        dfs(root);
        int maxF = 0;
        for (auto& [k, v] : count) maxF = std::max(maxF, v);

        std::vector<int> res;
        for (auto& [k, v] : count) {
            if (v == maxF) res.push_back(k);
        }
        return res;
    }
};