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
public:
    std::vector<int> unionBST(TreeNode* root1, TreeNode* root2) {
        std::vector<int> arr1, arr2;
        inorder(root1, arr1);
        inorder(root2, arr2);

        std::vector<int> res;
        size_t i = 0, j = 0;
        while (i < arr1.size() && j < arr2.size()) {
            if (arr1[i] == arr2[j]) {
                res.push_back(arr1[i]);
                i++;
                j++;
            } else if (arr1[i] < arr2[j]) {
                res.push_back(arr1[i++]);
            } else {
                res.push_back(arr2[j++]);
            }
        }
        while (i < arr1.size()) res.push_back(arr1[i++]);
        while (j < arr2.size()) res.push_back(arr2[j++]);

        return res;
    }
};