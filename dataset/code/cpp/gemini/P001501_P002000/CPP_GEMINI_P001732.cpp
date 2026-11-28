struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    bool isThreaded = false;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool verifyThreaded(TreeNode* root) {
        if (!root) return true;
        TreeNode* cur = root;
        while (cur->left) cur = cur->left;

        int count = 0;
        while (cur) {
            count++;
            if (cur->isThreaded) {
                cur = cur->right;
            } else {
                cur = cur->right;
                while (cur && cur->left) cur = cur->left;
            }
        }
        return count > 0;
    }
};