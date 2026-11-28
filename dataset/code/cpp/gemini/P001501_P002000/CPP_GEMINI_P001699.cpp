#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if (!root) return true;
        std::queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while (!q.empty()) {
            size_t size = q.size();
            int prev = -1;

            for (size_t i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (level % 2 == 0) {
                    if (node->val % 2 == 0 || (prev != -1 && node->val <= prev)) return false;
                } else {
                    if (node->val % 2 != 0 || (prev != -1 && node->val >= prev)) return false;
                }
                prev = node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            level++;
        }
        return true;
    }
};