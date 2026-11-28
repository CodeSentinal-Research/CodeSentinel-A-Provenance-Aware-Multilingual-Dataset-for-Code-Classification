#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
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
        int ans;
        if (dfs(root, ans)) {
            return ans;
        } else {
            return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
        }
    }

private:
    bool dfs(TreeNode* node, int& ans) {
        if (!node) {
            return true;
        }
        int leftSize = dfs(node->left, ans) ? (node->left ? node->left->val : 0) : INT_MIN;
        int rightSize = dfs(node->right, ans) ? (node->right ? node->right->val : 0) : INT_MIN;
        if (leftSize >= 0 && rightSize >= 0 && leftSize + node->val > node->val && rightSize + node->val > node->val) {
            ans = max(ans, leftSize + rightSize + 1);
            return true;
        }
        return false;
    }
};