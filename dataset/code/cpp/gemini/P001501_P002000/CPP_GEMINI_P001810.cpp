struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int curSum = 0;

    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        curSum += node->val;
        node->val = curSum;
        inorder(node->right);
    }
public:
    TreeNode* bstToCumulative(TreeNode* root) {
        curSum = 0;
        inorder(root);
        return root;
    }
};