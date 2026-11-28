#include <vector>
#include <queue>
#include <climits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* constructBST(std::vector<int>& levelOrder) {
        if (levelOrder.empty()) return nullptr;
        TreeNode* root = new TreeNode(levelOrder[0]);
        std::queue<std::tuple<TreeNode*, long long, long long>> q;
        q.push({root, LLONG_MIN, LLONG_MAX});
        size_t idx = 1;

        while (!q.empty() && idx < levelOrder.size()) {
            auto [node, low, high] = q.front();
            q.pop();

            if (idx < levelOrder.size() && levelOrder[idx] > low && levelOrder[idx] < node->val) {
                node->left = new TreeNode(levelOrder[idx]);
                q.push({node->left, low, node->val});
                idx++;
            }
            if (idx < levelOrder.size() && levelOrder[idx] > node->val && levelOrder[idx] < high) {
                node->right = new TreeNode(levelOrder[idx]);
                q.push({node->right, node->val, high});
                idx++;
            }
        }
        return root;
    }
};