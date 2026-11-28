#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int idx = 0;

    void inorder(TreeNode* node, std::vector<int>& vals) {
        if (!node) return;
        inorder(node->left, vals);
        vals.push_back(node->val);
        inorder(node->right, vals);
    }

    void preorder(TreeNode* node, std::vector<int>& vals) {
        if (!node) return;
        node->val = vals[idx++];
        preorder(node->left, vals);
        preorder(node->right, vals);
    }
public:
    TreeNode* convertToMinHeap(TreeNode* root) {
        std::vector<int> vals;
        inorder(root, vals);
        idx = 0;
        preorder(root, vals);
        return root;
    }
};