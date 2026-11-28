struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int countPaths(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        return countPaths(root->left) + countPaths(root->right);
    }
};