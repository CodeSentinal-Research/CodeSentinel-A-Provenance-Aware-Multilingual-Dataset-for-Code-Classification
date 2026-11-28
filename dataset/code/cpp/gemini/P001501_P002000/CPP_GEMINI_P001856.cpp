struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    TreeNode *head = nullptr, *prev = nullptr;

    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        if (!head) {
            head = node;
        } else {
            prev->right = node;
            node->left = prev;
        }
        prev = node;
        inorder(node->right);
    }
public:
    TreeNode* treeToDoublyList(TreeNode* root) {
        if (!root) return nullptr;
        head = prev = nullptr;
        inorder(root);
        prev->right = head;
        head->left = prev;
        return head;
    }
};