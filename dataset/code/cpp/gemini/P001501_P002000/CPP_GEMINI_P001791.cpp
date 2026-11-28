struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxValue(TreeNode* root) {
        if (!root) return -1;
        TreeNode* cur = root;
        while (cur->right) cur = cur->right;
        return cur->val;
    }
};