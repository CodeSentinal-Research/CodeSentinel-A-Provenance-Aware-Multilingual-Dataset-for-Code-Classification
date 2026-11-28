struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int largestSmaller(TreeNode* root, int key) {
        int ans = -1;
        TreeNode* cur = root;

        while (cur) {
            if (cur->val < key) {
                ans = cur->val;
                cur = cur->right;
            } else {
                cur = cur->left;
            }
        }
        return ans;
    }
};