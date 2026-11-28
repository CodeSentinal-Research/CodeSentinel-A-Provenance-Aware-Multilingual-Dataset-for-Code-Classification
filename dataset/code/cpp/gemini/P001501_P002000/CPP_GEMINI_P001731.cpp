struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    bool isThreaded = false;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    TreeNode* prev = nullptr;

    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        if (prev && !prev->right) {
            prev->right = node;
            prev->isThreaded = true;
        }
        prev = node;
        inorder(node->right);
    }
public:
    TreeNode* convertToThreaded(TreeNode* root) {
        prev = nullptr;
        inorder(root);
        return root;
    }
};