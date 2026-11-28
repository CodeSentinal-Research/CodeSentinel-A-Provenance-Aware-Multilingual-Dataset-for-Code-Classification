#include <climits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int minDepth = INT_MAX, res = -1;

    TreeNode* lca(TreeNode* node, int p, int q) {
        if (!node || node->val == p || node->val == q) return node;
        TreeNode* l = lca(node->left, p, q);
        TreeNode* r = lca(node->right, p, q);
        if (l && r) return node;
        return l ? l : r;
    }

    void findLeaf(TreeNode* node, int depth) {
        if (!node) return;
        if (!node->left && !node->right) {
            if (depth < minDepth) {
                minDepth = depth;
                res = node->val;
            }
            return;
        }
        findLeaf(node->left, depth + 1);
        findLeaf(node->right, depth + 1);
    }
public:
    int nearestCommonLeaf(TreeNode* root, int p, int q) {
        TreeNode* ancestor = lca(root, p, q);
        minDepth = INT_MAX;
        res = -1;
        findLeaf(ancestor, 0);
        return res;
    }
};