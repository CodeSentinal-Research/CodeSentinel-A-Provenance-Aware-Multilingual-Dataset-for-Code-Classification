Here is the C++ solution for the problem:

#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
public:
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

private:
    int maxSumHelper(TreeNode* node, int& maxSum) {
        if (node == NULL) {
            return 0;
        }

        int left = max(0, maxSumHelper(node->left, maxSum));
        int right = max(0, maxSumHelper(node->right, maxSum));

        maxSum = max(maxSum, left + right + node->val);

        return max(left + node->val, right + node->val);
    }
};

In the above code, the TreeNode class is used to represent a node in the binary tree. The Solution class has a method maxPathSum which takes a root node of the tree as input and returns the maximum path sum which can be obtained from any node to any leaf in the tree. The maxSumHelper function is a recursive function which calculates the maximum path sum for a given node.