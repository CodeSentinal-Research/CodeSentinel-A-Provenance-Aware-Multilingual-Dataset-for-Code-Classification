struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int curSum = 0;

    void reverseInorder(TreeNode* node) {
        if (!node) return;
        reverseInorder(node->right);
        curSum += node->val;
        node->val = curSum;
        reverseInorder(node->left);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        curSum = 0;
        reverseInorder(root);
        return root;
    }
};