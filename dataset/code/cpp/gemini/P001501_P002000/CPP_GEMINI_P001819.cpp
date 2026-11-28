struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int rank = 0;

    bool inorder(TreeNode* node, int key) {
        if (!node) return false;
        if (inorder(node->left, key)) return true;
        if (node->val == key) {
            rank++;
            return true;
        }
        if (node->val < key) rank++;
        return inorder(node->right, key);
    }
public:
    int rankOfKey(TreeNode* root, int key) {
        rank = 0;
        bool found = inorder(root, key);
        return found ? rank : -1;
    }
};