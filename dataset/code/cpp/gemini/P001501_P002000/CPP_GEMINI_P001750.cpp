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
    int minNodesLevel(TreeNode* root) {
        if (!root) return 0;
        std::queue<TreeNode*> q;
        q.push(root);
        int minNodes = INT_MAX, minLevel = 1, curLevel = 1;

        while (!q.empty()) {
            size_t size = q.size();
            if ((int)size < minNodes) {
                minNodes = size;
                minLevel = curLevel;
            }
            for (size_t i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            curLevel++;
        }
        return minLevel;
    }
};