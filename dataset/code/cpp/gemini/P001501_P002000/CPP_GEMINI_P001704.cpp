struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isIsomorphic(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return true;
        if (!root1 || !root2 || root1->val != root2->val) return false;
        return (isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right)) ||
               (isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->right, root2->left));
    }
};