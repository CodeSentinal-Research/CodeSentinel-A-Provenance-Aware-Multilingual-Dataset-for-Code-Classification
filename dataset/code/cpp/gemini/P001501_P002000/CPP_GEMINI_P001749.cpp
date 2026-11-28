struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isStrictBinaryTree(TreeNode* root) {
        if (!root) return true;
        if (!root->left && !root->right) return true;
        if (root->left && root->right) {
            return isStrictBinaryTree(root->left) && isStrictBinaryTree(root->right);
        }
        return false;
    }
};