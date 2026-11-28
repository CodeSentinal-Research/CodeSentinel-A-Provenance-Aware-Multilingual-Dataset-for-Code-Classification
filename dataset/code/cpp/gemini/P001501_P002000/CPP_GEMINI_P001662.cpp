#include <algorithm>
#include <cmath>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int check(TreeNode* node) {
        if (!node) return 0;
        int l = check(node->left);
        if (l == -1) return -1;
        int r = check(node->right);
        if (r == -1 || std::abs(l - r) > 1) return -1;
        return 1 + std::max(l, r);
    }
public:
    bool isBalanced(TreeNode* root) {
        return check(root) != -1;
    }
};