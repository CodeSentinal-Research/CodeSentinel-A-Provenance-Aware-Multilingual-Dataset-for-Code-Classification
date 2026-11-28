#include <climits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int count = 0;

    void dfs(TreeNode* node, int low, int high) {
        if (!node) return;
        if (low == high) {
            count++;
            return;
        }
        dfs(node->left, low, node->val - 1);
        dfs(node->right, node->val + 1, high);
    }
public:
    int countDeadEnds(TreeNode* root) {
        count = 0;
        dfs(root, 1, INT_MAX);
        return count;
    }
};