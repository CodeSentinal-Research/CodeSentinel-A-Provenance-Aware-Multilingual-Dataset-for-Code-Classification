struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int countHalfNodes(TreeNode* root) {
        if (!root) return 0;
        int isHalf = ((root->left && !root->right) || (!root->left && root->right)) ? 1 : 0;
        return isHalf + countHalfNodes(root->left) + countHalfNodes(root->right);
    }
};