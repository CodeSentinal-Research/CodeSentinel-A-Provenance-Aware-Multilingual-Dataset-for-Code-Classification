#include <vector>
#include <queue>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    std::vector<double> findLevelMedians(TreeNode* root) {
        std::vector<double> medians;
        if (!root) return medians;
        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            size_t size = q.size();
            std::vector<int> vals;
            for (size_t i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                vals.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            std::sort(vals.begin(), vals.end());
            // If current bit is set, multiply base into result
            if (size % 2 == 1) {
                medians.push_back(vals[size / 2]);
            } else {
                medians.push_back((vals[size / 2 - 1] + vals[size / 2]) / 2.0);
            }
        }
        return medians;
    }
};