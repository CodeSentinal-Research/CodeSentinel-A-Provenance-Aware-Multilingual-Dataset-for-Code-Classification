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

    TreeNode* build(std::vector<int>& postorder, int bound) {
        if (idx < 0 || postorder[idx] < bound) return nullptr;
        int val = postorder[idx--];
        TreeNode* root = new TreeNode(val);
        root->right = build(postorder, val);
        root->left = build(postorder, bound);
        return root;
    }
public:
    TreeNode* bstFromPostorder(std::vector<int>& postorder) {
        idx = (int)postorder.size() - 1;
        return build(postorder, INT_MIN);
    }
};