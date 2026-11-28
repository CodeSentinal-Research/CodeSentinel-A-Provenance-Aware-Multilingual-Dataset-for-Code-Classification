struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* removeHalfNodes(TreeNode* root) {
        if (!root) return nullptr;
        root->left = removeHalfNodes(root->left);
        root->right = removeHalfNodes(root->right);

        if (!root->left && !root->right) return root;
        if (!root->left) return root->right;
        if (!root->right) return root->left;

        return root;
    }
};