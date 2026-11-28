struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int check(TreeNode* node) {
        if (!node) return 0;
        if (!node->left && !node->right) return node->val;
        int lSum = check(node->left);
        int rSum = check(node->right);
        if (lSum == -1 || rSum == -1 || node->val != lSum + rSum) return -1;
        return node->val + lSum + rSum;
    }
public:
    bool isSumTree(TreeNode* root) {
        return check(root) != -1;
    }
};