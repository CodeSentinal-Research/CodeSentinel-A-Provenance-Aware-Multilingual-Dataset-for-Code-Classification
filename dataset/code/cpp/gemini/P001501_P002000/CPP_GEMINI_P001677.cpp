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
    std::vector<int> findCousins(TreeNode* root, int targetVal) {
        std::vector<int> res;
        if (!root || root->val == targetVal) return res;

        std::queue<TreeNode*> q;
        q.push(root);
        bool found = false;

        while (!q.empty() && !found) {
            size_t size = q.size();
            for (size_t i = 0; i < size; i++) {
                TreeNode* cur = q.front();
                q.pop();

                if ((cur->left && cur->left->val == targetVal) || (cur->right && cur->right->val == targetVal)) {
                    found = true;
                } else {
                    if (cur->left) q.push(cur->left);
                    if (cur->right) q.push(cur->right);
                }
            }
        }

        if (found) {
            while (!q.empty()) {
                res.push_back(q.front()->val);
                q.pop();
            }
        }
        return res;
    }
};