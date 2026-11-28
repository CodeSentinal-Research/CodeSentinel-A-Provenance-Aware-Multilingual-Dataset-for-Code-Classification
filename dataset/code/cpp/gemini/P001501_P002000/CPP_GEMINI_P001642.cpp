#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int ans = 0;
    int depth(TreeNode* node) {
        if (!node) return 0;
        int l = depth(node->left);
        int r = depth(node->right);
        ans = std::max(ans, l + r);
        return 1 + std::max(l, r);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        depth(root);
        return ans;
    }
};