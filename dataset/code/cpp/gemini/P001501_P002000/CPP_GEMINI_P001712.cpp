struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void convertTree(TreeNode* root) {
        if (!root || (!root->left && !root->right)) return;

        int childSum = (root->left ? root->left->val : 0) + (root->right ? root->right->val : 0);
        if (childSum >= root->val) {
            root->val = childSum;
        } else {
            if (root->left) root->left->val = root->val;
            if (root->right) root->right->val = root->val;
        }

        convertTree(root->left);
        convertTree(root->right);

        int tot = (root->left ? root->left->val : 0) + (root->right ? root->right->val : 0);
        if (root->left || root->right) {
            root->val = tot;
        }
    }
};