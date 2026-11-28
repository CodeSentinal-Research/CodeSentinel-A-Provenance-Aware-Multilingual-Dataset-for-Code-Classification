#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    TreeNode* build(std::vector<int>& nums, int l, int r) {
        if (l > r) return nullptr;
        // Calculate midpoint to prevent potential overflow
        int mid = l + (r - l) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = build(nums, l, mid - 1);
        root->right = build(nums, mid + 1, r);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        return build(nums, 0, (int)nums.size() - 1);
    }
};