#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int levelOrderSuccessor(TreeNode* root, int targetVal) {
        if (!root) return -1;
        std::queue<TreeNode*> q;
        q.push(root);
        bool found = false;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (found) return node->val;
            if (node->val == targetVal) found = true;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        return -1;
    }
};