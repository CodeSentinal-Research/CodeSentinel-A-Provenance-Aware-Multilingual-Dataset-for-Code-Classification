struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int minValue(TreeNode* root) {
        if (!root) return -1;
        TreeNode* cur = root;
        while (cur->left) cur = cur->left;
        return cur->val;
    }
};