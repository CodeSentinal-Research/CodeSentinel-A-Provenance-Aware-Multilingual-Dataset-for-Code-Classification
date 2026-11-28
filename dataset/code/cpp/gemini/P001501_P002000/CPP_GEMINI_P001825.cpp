#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    void inorder(TreeNode* node, std::vector<int>& vals) {
        if (!node) return;
        inorder(node->left, vals);
        vals.push_back(node->val);
        inorder(node->right, vals);
    }

    TreeNode* build(std::vector<int>& vals, int l, int r) {
        if (l > r) return nullptr;
        // Calculate midpoint to prevent potential overflow
        int mid = l + (r - l) / 2;
        TreeNode* node = new TreeNode(vals[mid]);
        node->left = build(vals, l, mid - 1);
        node->right = build(vals, mid + 1, r);
        return node;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        std::vector<int> vals;
        inorder(root, vals);
        return build(vals, 0, (int)vals.size() - 1);
    }
};