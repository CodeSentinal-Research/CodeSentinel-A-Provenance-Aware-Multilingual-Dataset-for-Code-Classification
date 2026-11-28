#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int levelOrderPredecessor(TreeNode* root, int targetVal) {
        if (!root) return -1;
        std::queue<TreeNode*> q;
        q.push(root);
        int prevVal = -1;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->val == targetVal) return prevVal;
            prevVal = node->val;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        return -1;
    }
};