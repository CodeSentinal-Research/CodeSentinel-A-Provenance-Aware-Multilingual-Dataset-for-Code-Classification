#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int countNodes(TreeNode* node) {
        if (!node) return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    int getHeight(TreeNode* node) {
        if (!node) return 0;
        return 1 + std::max(getHeight(node->left), getHeight(node->right));
    }
public:
    int minInsertionsToCompleteBST(TreeNode* root) {
        int n = countNodes(root);
        int h = getHeight(root);
        int minNodes = 1 << (h - 1);
        return std::max(0, minNodes - n);
    }
};