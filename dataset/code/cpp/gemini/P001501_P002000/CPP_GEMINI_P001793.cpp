struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* inorderPredecessor(TreeNode* root, TreeNode* p) {
        TreeNode* pred = nullptr;
        TreeNode* cur = root;
        while (cur) {
            if (cur->val < p->val) {
                pred = cur;
                cur = cur->right;
            } else {
                cur = cur->left;
            }
        }
        return pred;
    }
};