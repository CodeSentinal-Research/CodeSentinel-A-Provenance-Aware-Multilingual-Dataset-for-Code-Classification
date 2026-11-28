#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int maxSize = 0;

    bool isMirror(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return true;
        if (!t1 || !t2 || t1->val != t2->val) return false;
        return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
    }

    int treeSize(TreeNode* node) {
        if (!node) return 0;
        return 1 + treeSize(node->left) + treeSize(node->right);
    }

    void dfs(TreeNode* node) {
        if (!node) return;
        if (isMirror(node->left, node->right)) {
            maxSize = std::max(maxSize, treeSize(node));
        }
        dfs(node->left);
        dfs(node->right);
    }
public:
    int largestSymmetricSubtree(TreeNode* root) {
        maxSize = 0;
        dfs(root);
        return maxSize;
    }
};