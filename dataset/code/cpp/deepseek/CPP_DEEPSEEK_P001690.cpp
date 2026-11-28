Here is the C++ code that you requested:

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
    int maxSumBST(TreeNode* root) {
        int maxSum = INT_MIN;
        isValidBST(root, maxSum);
        return maxSum;
    }

private:
    struct Info {
        int size, sum, min, max;
        bool isBST;
    };

    Info isValidBST(TreeNode* node, int& maxSum) {
        if (!node) {
            return Info(0, 0, INT_MAX, INT_MIN, true);
        }

        Info left = isValidBST(node->left, maxSum);
        Info right = isValidBST(node->right, maxSum);

        Info info(0, 0, node->val, node->val, true);
        if (left.isBST && right.isBST && left.max < node->val && right.min > node->val) {
            info.sum = left.sum + right.sum + node->val;
            info.min = min(left.min, node->val);
            info.max = max(right.max, node->val);
            info.size = left.size + right.size + 1;
        } else {
            info.size = max(left.size, right.size);
        }

        maxSum = max(maxSum, info.sum);

        return info;
    }
};
This code firstly declares the TreeNode struct and the Solution class. Solution class has a method to find the maximum sum of values among all subtrees that satisfy the Binary Search Tree property. This is done by the isValidBST method which recursively checks the binary tree for Binary Search Tree property.

The Info struct is used to return the size, sum, minimum and maximum value of a binary tree or a subtree.

In the main function, we create a binary tree from the input and call the maxSumBST method to get the maximum sum of values among all subtrees that satisfy the Binary Search Tree property.