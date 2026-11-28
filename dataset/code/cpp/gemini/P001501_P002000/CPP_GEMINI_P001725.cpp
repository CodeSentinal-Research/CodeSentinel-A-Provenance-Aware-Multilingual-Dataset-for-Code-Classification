struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        if (!root->left && !root->right) return root->val == targetSum ? 1 : 0;
        return pathSum(root->left, targetSum - root->val) + pathSum(root->right, targetSum - root->val);
    }
};