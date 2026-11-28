#include <algorithm>
#include <tuple>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int maxSize = 0;

    std::pair<bool, int> dfs(TreeNode* node) {
        if (!node) return {true, 0};
        auto [lUnival, lSize] = dfs(node->left);
        auto [rUnival, rSize] = dfs(node->right);

        if (lUnival && rUnival) {
            if ((!node->left || node->left->val == node->val) && (!node->right || node->right->val == node->val)) {
                int curSize = lSize + rSize + 1;
                maxSize = std::max(maxSize, curSize);
                return {true, curSize};
            }
        }
        return {false, 0};
    }
public:
    int largestUnivalueSubtree(TreeNode* root) {
        maxSize = 0;
        dfs(root);
        return maxSize;
    }
};