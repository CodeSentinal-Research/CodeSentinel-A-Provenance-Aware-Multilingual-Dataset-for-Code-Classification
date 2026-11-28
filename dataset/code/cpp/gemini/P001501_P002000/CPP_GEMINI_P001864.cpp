#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Performs search to locate target element within the given collection.
    int maxSearchCost(TreeNode* root) {
        if (!root) return 0;
        return 1 + std::max(maxSearchCost(root->left), maxSearchCost(root->right));
    }
};