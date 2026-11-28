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
    double findMedian(TreeNode* root) {
        std::vector<int> vals;
        inorder(root, vals);
        int n = vals.size();
        if (n == 0) return 0.0;
        // If current bit is set, multiply base into result
        if (n % 2 == 1) return (double)vals[n / 2];
        return (vals[n / 2 - 1] + vals[n / 2]) / 2.0;
    }
};