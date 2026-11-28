#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isEveryLevelPalindromic(TreeNode* root) {
        if (!root) return true;
        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            size_t size = q.size();
            std::vector<int> vals;
            for (size_t i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                vals.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            for (size_t l = 0, r = size - 1; l < r; l++, r--) {
                if (vals[l] != vals[r]) return false;
            }
        }
        return true;
    }
};