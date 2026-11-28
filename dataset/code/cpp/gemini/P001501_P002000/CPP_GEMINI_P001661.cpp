struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    bool isFoldableMirror(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return true;
        if (!t1 || !t2) return false;
        return isFoldableMirror(t1->left, t2->right) && isFoldableMirror(t1->right, t2->left);
    }
public:
    bool isFoldable(TreeNode* root) {
        if (!root) return true;
        return isFoldableMirror(root->left, root->right);
    }
};