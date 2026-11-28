struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int lDepth = 0, rDepth = 0;
        TreeNode *l = root, *r = root;

        while (l) {
            lDepth++;
            l = l->left;
        }
        while (r) {
            rDepth++;
            r = r->right;
        }

        if (lDepth == rDepth) return (1 << lDepth) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};