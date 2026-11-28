#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        if (!root) return 0;
        int ret = dfs(root, INT_MAX, INT_MIN);
        return max(ret, max(largestBSTSubtree(root->left), largestBSTSubtree(root->right)));
    }

    int dfs(TreeNode* root, int lower, int upper) {
        if (!root) return 0;
        if (root->val < lower || root->val > upper) return -1;
        int left = dfs(root->left, lower, root->val);
        int right = dfs(root->right, root->val, upper);
        if (left == -1 || right == -1) return -1;
        return left + right + 1;
    }
};