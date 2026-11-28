struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* succ = nullptr;
        TreeNode* cur = root;
        while (cur) {
            if (cur->val > p->val) {
                succ = cur;
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
        return succ;
    }
};