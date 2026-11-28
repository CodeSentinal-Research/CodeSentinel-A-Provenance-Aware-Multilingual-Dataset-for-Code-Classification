#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int firstNonFullNode(TreeNode* root) {
        if (!root) return -1;
        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (!node->left || !node->right) return node->val;
            q.push(node->left);
            q.push(node->right);
        }
        return -1;
    }
};