struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool everyLeafHasSibling(TreeNode* root) {
        if (!root || (!root->left && !root->right)) return true;
        if (root->left && !root->right && !root->left->left && !root->left->right) return false;
        if (root->right && !root->left && !root->right->left && !root->right->right) return false;
        return everyLeafHasSibling(root->left) && everyLeafHasSibling(root->right);
    }
};