struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int cameras = 0;

    int dfs(TreeNode* node) {
        if (!node) return 2;
        int l = dfs(node->left);
        int r = dfs(node->right);

        if (l == 0 || r == 0) {
            cameras++;
            return 1;
        }
        if (l == 1 || r == 1) return 2;
        return 0;
    }
public:
    int minCameraCover(TreeNode* root) {
        cameras = 0;
        if (dfs(root) == 0) cameras++;
        return cameras;
    }
};