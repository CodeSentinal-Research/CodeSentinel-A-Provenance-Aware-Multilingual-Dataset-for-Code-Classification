Here is the C++ code:

#include <iostream>
#include <vector>
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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxSumHelper(root, maxSum);
        return maxSum;
    }

    int maxSumHelper(TreeNode* root, int& maxSum) {
        if (root == NULL) {
            return 0;
        }

        int left = max(0, maxSumHelper(root->left, maxSum));
        int right = max(0, maxSumHelper(root->right, maxSum));

        maxSum = max(maxSum, left + right + root->val);

        return max(left, right) + root->val;
    }
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    cout << s.maxPathSum(root) << endl;  
    return 0;
}

This program creates a binary tree from the input, then calls the `maxPathSum` function to find the maximum path sum. The `maxPathSum` function uses recursion to calculate the maximum sum of the path from each node to its leaf. It keeps track of the maximum sum found so far and updates it whenever a larger sum is found.