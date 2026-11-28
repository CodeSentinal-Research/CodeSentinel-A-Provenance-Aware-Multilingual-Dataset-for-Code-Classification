#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int maxSize = 0;

    int dfs(TreeNode* node) {
        if (!node) return 0;
        int l = dfs(node->left);
        int r = dfs(node->right);

        if (l != -1 && r != -1 && l == r) {
            int depth = l + 1;
            int size = (1 << depth) - 1;
            maxSize = std::max(maxSize, size);
            return depth;
        }

        return -1;
    }
public:
    int largestPerfectSubtree(TreeNode* root) {
        maxSize = 0;
        dfs(root);
        return maxSize;
    }
};