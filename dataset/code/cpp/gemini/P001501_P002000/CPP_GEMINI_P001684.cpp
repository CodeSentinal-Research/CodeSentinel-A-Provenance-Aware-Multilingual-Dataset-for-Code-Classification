struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSiblings(TreeNode* root, int a, int b) {
        if (!root) return false;
        if (root->left && root->right) {
            if ((root->left->val == a && root->right->val == b) || (root->left->val == b && root->right->val == a)) {
                return true;
            }
        }
        return isSiblings(root->left, a, b) || isSiblings(root->right, a, b);
    }
};