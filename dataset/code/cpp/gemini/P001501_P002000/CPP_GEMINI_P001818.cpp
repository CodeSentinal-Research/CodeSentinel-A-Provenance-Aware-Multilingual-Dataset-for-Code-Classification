#include <vector>
#include <climits>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lcaMultipleBST(TreeNode* root, std::vector<TreeNode*>& nodes) {
        int minVal = INT_MAX, maxVal = INT_MIN;
        for (auto* n : nodes) {
            minVal = std::min(minVal, n->val);
            maxVal = std::max(maxVal, n->val);
        }

        TreeNode* cur = root;
        while (cur) {
            if (maxVal < cur->val) {
                cur = cur->left;
            } else if (minVal > cur->val) {
                cur = cur->right;
            } else {
                return cur;
            }
        }
        return nullptr;
    }
};