#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    void inorder(TreeNode* node, int low, int high, std::vector<int>& res) {
        if (!node) return;
        if (node->val > low) inorder(node->left, low, high, res);
        if (node->val >= low && node->val <= high) res.push_back(node->val);
        if (node->val < high) inorder(node->right, low, high, res);
    }
public:
    std::vector<int> rangeSearch(TreeNode* root, int low, int high) {
        std::vector<int> res;
        inorder(root, low, high, res);
        return res;
    }
};