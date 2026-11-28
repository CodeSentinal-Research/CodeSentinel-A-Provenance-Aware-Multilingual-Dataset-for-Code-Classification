struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    TreeNode *first = nullptr, *last = nullptr;

    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        if (last) {
            last->right = node;
            node->left = last;
        } else {
            first = node;
        }
        last = node;
        inorder(node->right);
    }
public:
    TreeNode* treeToDoublyList(TreeNode* root) {
        if (!root) return nullptr;
        first = last = nullptr;
        inorder(root);
        last->right = first;
        first->left = last;
        return first;
    }
};