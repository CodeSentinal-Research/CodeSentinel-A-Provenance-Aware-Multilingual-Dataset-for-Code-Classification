#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxAdjacentLevelDiff(TreeNode* root) {
        if (!root) return 0;
        std::queue<TreeNode*> q;
        q.push(root);
        std::vector<long long> levelSums;

        while (!q.empty()) {
            size_t size = q.size();
            long long curSum = 0;
            for (size_t i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                curSum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            levelSums.push_back(curSum);
        }

        long long maxDiff = 0;
        for (size_t i = 1; i < levelSums.size(); i++) {
            maxDiff = std::max(maxDiff, std::abs(levelSums[i] - levelSums[i - 1]));
        }
        return maxDiff;
    }
};