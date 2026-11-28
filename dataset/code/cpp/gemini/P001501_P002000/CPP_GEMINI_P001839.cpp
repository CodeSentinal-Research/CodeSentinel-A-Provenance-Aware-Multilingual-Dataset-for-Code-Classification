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
    bool findTriplet(TreeNode* root, int target) {
        std::vector<int> vals;
        inorder(root, vals);
        int n = vals.size();

        for (int i = 0; i < n - 2; i++) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = vals[i] + vals[l] + vals[r];
                if (sum == target) return true;
                else if (sum < target) l++;
                else r--;
            }
        }
        return false;
    }
};