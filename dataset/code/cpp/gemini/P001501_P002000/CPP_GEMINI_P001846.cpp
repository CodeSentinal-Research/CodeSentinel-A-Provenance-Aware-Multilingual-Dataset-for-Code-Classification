#include <climits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    long long prev = LLONG_MIN;
    bool possible = true;

    void inorder(TreeNode* node) {
        if (!node || !possible) return;
        inorder(node->left);
        if (node->val <= prev) {
            possible = false;
            return;
        }
        prev = node->val;
        inorder(node->right);
    }
public:
    bool canBeBSTByRotations(TreeNode* root) {
        prev = LLONG_MIN;
        possible = true;
        inorder(root);
        return possible;
    }
};