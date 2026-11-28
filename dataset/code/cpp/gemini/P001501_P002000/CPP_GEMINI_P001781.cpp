struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int count = 0;

    bool isMirror(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return true;
        if (!t1 || !t2 || t1->val != t2->val) return false;
        return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
    }

    void dfs(TreeNode* node) {
        if (!node) return;
        if (isMirror(node->left, node->right)) count++;
        dfs(node->left);
        dfs(node->right);
    }
public:
    int countSymmetricSubtrees(TreeNode* root) {
        count = 0;
        dfs(root);
        return count;
    }
};