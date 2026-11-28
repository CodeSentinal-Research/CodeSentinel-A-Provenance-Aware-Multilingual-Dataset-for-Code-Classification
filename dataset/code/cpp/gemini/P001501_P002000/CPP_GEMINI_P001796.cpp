#include <vector>
#include <climits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int idx = 0;

    TreeNode* build(std::vector<int>& preorder, int bound) {
        if (idx == (int)preorder.size() || preorder[idx] > bound) return nullptr;
        int val = preorder[idx++];
        TreeNode* root = new TreeNode(val);
        root->left = build(preorder, val);
        root->right = build(preorder, bound);
        return root;
    }
public:
    TreeNode* bstFromPreorder(std::vector<int>& preorder) {
        idx = 0;
        return build(preorder, INT_MAX);
    }
};