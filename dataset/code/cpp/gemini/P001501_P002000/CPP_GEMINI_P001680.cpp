#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    std::vector<int> largestValues(TreeNode* root) {
        std::vector<int> res;
        if (!root) return res;

        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            size_t size = q.size();
            int maxVal = INT_MIN;
            for (size_t i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                maxVal = std::max(maxVal, node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(maxVal);
        }
        return res;
    }
};