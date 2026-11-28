#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxLeafLevel(TreeNode* root) {
        if (!root) return 0;
        std::queue<TreeNode*> q;
        q.push(root);
        int maxLeaves = -1, maxLevel = 1, curLevel = 1;

        while (!q.empty()) {
            size_t size = q.size();
            int leafCount = 0;
            for (size_t i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (!node->left && !node->right) leafCount++;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (leafCount > maxLeaves) {
                maxLeaves = leafCount;
                maxLevel = curLevel;
            }
            curLevel++;
        }
        return maxLevel;
    }
};