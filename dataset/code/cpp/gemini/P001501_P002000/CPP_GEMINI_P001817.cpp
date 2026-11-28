struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int ceilBST(TreeNode* root, int key) {
        int ceilVal = -1;
        TreeNode* cur = root;

        while (cur) {
            if (cur->val == key) {
                return cur->val;
            } else if (cur->val > key) {
                ceilVal = cur->val;
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
        return ceilVal;
    }
};