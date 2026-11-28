struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int dfs(TreeNode* node, int curVal) {
        if (!node) return 0;
        curVal = (curVal << 1) | node->val;
        if (!node->left && !node->right) return curVal;
        return dfs(node->left, curVal) + dfs(node->right, curVal);
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
};