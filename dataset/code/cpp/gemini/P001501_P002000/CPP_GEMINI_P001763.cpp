struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int count = 0;

    bool dfs(TreeNode* node) {
        if (!node) return true;
        bool l = dfs(node->left);
        bool r = dfs(node->right);

        if (l && r) {
            if ((!node->left || node->left->val == node->val) && 
                (!node->right || node->right->val == node->val)) {
                count++;
                return true;
            }
        }
        return false;
    }
public:
    int countUnivalSubtrees(TreeNode* root) {
        count = 0;
        dfs(root);
        return count;
    }
};