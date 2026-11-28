#include <unordered_map>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    std::unordered_map<long long, int> prefixCount;

    int dfs(TreeNode* node, long long curSum, int targetSum) {
        if (!node) return 0;
        curSum += node->val;
        int res = prefixCount[curSum - targetSum];
        prefixCount[curSum]++;
        res += dfs(node->left, curSum, targetSum) + dfs(node->right, curSum, targetSum);
        prefixCount[curSum]--;
        return res;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        prefixCount.clear();
        prefixCount[0] = 1;
        return dfs(root, 0, targetSum);
    }
};