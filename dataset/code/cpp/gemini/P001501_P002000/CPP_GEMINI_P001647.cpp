#include <vector>
#include <map>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    std::vector<int> bottomView(TreeNode* root) {
        std::vector<int> res;
        if (!root) return res;

        std::map<int, int> botMap;
        std::queue<std::pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto [node, col] = q.front();
            q.pop();

            botMap[col] = node->val;
            if (node->left) q.push({node->left, col - 1});
            if (node->right) q.push({node->right, col + 1});
        }

        for (auto& [col, val] : botMap) {
            res.push_back(val);
        }
        return res;
    }
};