struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool checkChildrenSum(TreeNode* root) {
        if (!root || (!root->left && !root->right)) return true;
        int childSum = (root->left ? root->left->val : 0) + (root->right ? root->right->val : 0);
        if (root->val != childSum) return false;
        return checkChildrenSum(root->left) && checkChildrenSum(root->right);
    }
};