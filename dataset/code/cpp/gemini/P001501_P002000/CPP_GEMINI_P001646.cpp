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
    std::vector<int> topView(TreeNode* root) {
        std::vector<int> res;
        if (!root) return res;

        std::map<int, int> topMap;
        std::queue<std::pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto [node, col] = q.front();
            q.pop();

            if (!topMap.count(col)) {
                topMap[col] = node->val;
            }
            if (node->left) q.push({node->left, col - 1});
            if (node->right) q.push({node->right, col + 1});
        }

        for (auto& [col, val] : topMap) {
            res.push_back(val);
        }
        return res;
    }
};