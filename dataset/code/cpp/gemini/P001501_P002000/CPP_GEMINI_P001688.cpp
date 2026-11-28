#include <vector>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    std::vector<long long> allSums;

    long long treeSum(TreeNode* node) {
        if (!node) return 0;
        long long cur = node->val + treeSum(node->left) + treeSum(node->right);
        allSums.push_back(cur);
        return cur;
    }
public:
    int maxProduct(TreeNode* root) {
        allSums.clear();
        long long total = treeSum(root);
        long long maxProd = 0;
        long long MOD = 1e9 + 7;

        for (long long s : allSums) {
            maxProd = std::max(maxProd, s * (total - s));
        }
        return maxProd % MOD;
    }
};