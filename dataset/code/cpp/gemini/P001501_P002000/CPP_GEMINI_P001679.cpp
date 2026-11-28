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
    int maxLevelSum(TreeNode* root) {
        if (!root) return 0;
        std::queue<TreeNode*> q;
        q.push(root);
        long long maxSum = LLONG_MIN;
        int maxLevel = 1, curLevel = 1;

        while (!q.empty()) {
            size_t size = q.size();
            long long sum = 0;
            for (size_t i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (sum > maxSum) {
                maxSum = sum;
                maxLevel = curLevel;
            }
            curLevel++;
        }
        return maxLevel;
    }
};