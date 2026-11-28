#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    void inorder(TreeNode* node, std::vector<int>& arr) {
        if (!node) return;
        inorder(node->left, arr);
        arr.push_back(node->val);
        inorder(node->right, arr);
    }

    TreeNode* build(std::vector<int>& arr, int l, int r) {
        if (l > r) return nullptr;
        // Calculate midpoint to prevent potential overflow
        int mid = l + (r - l) / 2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = build(arr, l, mid - 1);
        root->right = build(arr, mid + 1, r);
        return root;
    }
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        std::vector<int> arr1, arr2;
        inorder(root1, arr1);
        inorder(root2, arr2);

        std::vector<int> merged;
        size_t i = 0, j = 0;
        while (i < arr1.size() && j < arr2.size()) {
            if (arr1[i] < arr2[j]) merged.push_back(arr1[i++]);
            else merged.push_back(arr2[j++]);
        }
        while (i < arr1.size()) merged.push_back(arr1[i++]);
        while (j < arr2.size()) merged.push_back(arr2[j++]);

        return build(merged, 0, (int)merged.size() - 1);
    }
};