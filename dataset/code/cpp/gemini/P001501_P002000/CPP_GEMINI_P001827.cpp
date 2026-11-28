struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isStructurallyIdentical(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return true;
        if (!root1 || !root2) return false;
        return isStructurallyIdentical(root1->left, root2->left) &&
               isStructurallyIdentical(root1->right, root2->right);
    }
};