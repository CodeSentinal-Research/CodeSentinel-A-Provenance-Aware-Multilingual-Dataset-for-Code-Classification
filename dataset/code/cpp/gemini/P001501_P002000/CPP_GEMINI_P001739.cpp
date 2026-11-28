struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* removeLeaves(TreeNode* root) {
        if (!root || (!root->left && !root->right)) return nullptr;
        root->left = removeLeaves(root->left);
        root->right = removeLeaves(root->right);
        return root;
    }
};