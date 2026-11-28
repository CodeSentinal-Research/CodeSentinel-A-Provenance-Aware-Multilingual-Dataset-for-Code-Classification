#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;
        std::queue<TreeNode*> q;
        q.push(root);
        bool sawNull = false;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (!node) {
                sawNull = true;
            } else {
                if (sawNull) return false;
                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
    }
};