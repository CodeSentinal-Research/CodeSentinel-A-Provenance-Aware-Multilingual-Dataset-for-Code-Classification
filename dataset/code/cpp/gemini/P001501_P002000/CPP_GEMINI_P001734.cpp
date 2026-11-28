struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int convert(TreeNode* node) {
        if (!node) return 0;
        int oldVal = node->val;
        int lSum = convert(node->left);
        int rSum = convert(node->right);
        node->val = lSum + rSum;
        return node->val + oldVal;
    }
public:
    void toSumTree(TreeNode* root) {
        convert(root);
    }
};