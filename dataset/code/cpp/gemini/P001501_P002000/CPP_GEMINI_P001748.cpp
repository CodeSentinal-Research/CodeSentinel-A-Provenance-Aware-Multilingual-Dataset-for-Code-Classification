struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int countInternalNodes(TreeNode* root) {
        if (!root || (!root->left && !root->right)) return 0;
        return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
    }
};