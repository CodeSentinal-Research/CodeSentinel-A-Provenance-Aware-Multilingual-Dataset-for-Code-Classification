struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool everyInternalNodeOneChild(TreeNode* root) {
        if (!root || (!root->left && !root->right)) return true;
        if (root->left && root->right) return false;
        return everyInternalNodeOneChild(root->left ? root->left : root->right);
    }
};