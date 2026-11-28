struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    TreeNode* insert(TreeNode* node, int val) {
        if (!node) return new TreeNode(val);
        if (val < node->val) node->left = insert(node->left, val);
        else node->right = insert(node->right, val);
        return node;
    }

    void addAll(TreeNode* root1, TreeNode* node) {
        if (!node) return;
        insert(root1, node->val);
        addAll(root1, node->left);
        addAll(root1, node->right);
    }
public:
    TreeNode* joinBST(TreeNode* root1, TreeNode* root2) {
        if (!root1) return root2;
        if (!root2) return root1;
        addAll(root1, root2);
        return root1;
    }
};