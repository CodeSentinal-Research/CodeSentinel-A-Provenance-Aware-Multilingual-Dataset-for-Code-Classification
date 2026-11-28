struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int countFullNodes(TreeNode* root) {
        if (!root) return 0;
        int isFull = (root->left && root->right) ? 1 : 0;
        return isFull + countFullNodes(root->left) + countFullNodes(root->right);
    }
};