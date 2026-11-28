struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isFull(TreeNode* root) {
        if (!root) return true;
        if (!root->left && !root->right) return true;
        if (root->left && root->right) {
            return isFull(root->left) && isFull(root->right);
        }
        return false;
    }
};