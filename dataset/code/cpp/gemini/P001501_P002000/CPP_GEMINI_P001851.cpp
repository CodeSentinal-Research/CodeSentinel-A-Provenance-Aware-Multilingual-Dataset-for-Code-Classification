#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    void preorder(TreeNode* node, std::vector<int>& res) {
        if (!node) return;
        res.push_back(node->val);
        preorder(node->left, res);
        preorder(node->right, res);
    }
public:
    std::vector<int> smallestInsertionSeq(TreeNode* root) {
        std::vector<int> res;
        preorder(root, res);
        return res;
    }
};