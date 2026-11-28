#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    void inorder(TreeNode* node, std::vector<int>& vals) {
        if (!node) return;
        inorder(node->left, vals);
        vals.push_back(node->val);
        inorder(node->right, vals);
    }
public:
    bool sameKeysBST(TreeNode* root1, TreeNode* root2) {
        std::vector<int> arr1, arr2;
        inorder(root1, arr1);
        inorder(root2, arr2);
        return arr1 == arr2;
    }
};