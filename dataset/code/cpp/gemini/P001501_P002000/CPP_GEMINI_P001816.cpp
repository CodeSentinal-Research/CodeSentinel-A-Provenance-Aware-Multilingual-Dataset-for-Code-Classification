struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int floorBST(TreeNode* root, int key) {
        int floorVal = -1;
        TreeNode* cur = root;

        while (cur) {
            if (cur->val == key) {
                return cur->val;
            } else if (cur->val < key) {
                floorVal = cur->val;
                cur = cur->right;
            } else {
                cur = cur->left;
            }
        }
        return floorVal;
    }
};