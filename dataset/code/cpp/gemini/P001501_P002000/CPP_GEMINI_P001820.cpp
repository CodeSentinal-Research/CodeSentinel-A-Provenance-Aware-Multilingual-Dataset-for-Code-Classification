struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int curRank = 0;
    int ans = -1;

    void inorder(TreeNode* node, int rank) {
        if (!node || ans != -1) return;
        inorder(node->left, rank);
        curRank++;
        if (curRank == rank) {
            ans = node->val;
            return;
        }
        inorder(node->right, rank);
    }
public:
    int keyWithRank(TreeNode* root, int rank) {
        curRank = 0;
        ans = -1;
        inorder(root, rank);
        return ans;
    }
};