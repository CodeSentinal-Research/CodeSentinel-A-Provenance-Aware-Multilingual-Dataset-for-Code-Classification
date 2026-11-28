struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int findDepth(TreeNode* node) {
        int d = 0;
        while (node) {
            d++;
            node = node->left;
        }
        return d;
    }

    bool check(TreeNode* node, int level, int d) {
        if (!node) return true;
        if (!node->left && !node->right) return level == d;
        if (!node->left || !node->right) return false;
        return check(node->left, level + 1, d) && check(node->right, level + 1, d);
    }
public:
    bool isPerfect(TreeNode* root) {
        int d = findDepth(root);
        return check(root, 1, d);
    }
};