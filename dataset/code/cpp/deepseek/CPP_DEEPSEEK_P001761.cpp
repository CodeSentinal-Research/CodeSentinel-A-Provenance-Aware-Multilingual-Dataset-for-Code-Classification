Here is a simple C++ solution for finding the subtree with maximum sum:

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
    int maxSum = INT_MIN;
    TreeNode* maxSubtree;

    int maxSubTreeSum(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int sum = root->val + maxSubTreeSum(root->left) + maxSubTreeSum(root->right);

        if (sum > maxSum) {
            maxSum = sum;
            maxSubtree = root;
        }

        return sum;
    }

    void solve(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        solve(root->left);
        solve(root->right);

        maxSubTreeSum(root);
    }

    void printPostOrder(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        printPostOrder(root->left);
        printPostOrder(root->right);

        cout << root->val << " ";
    }

    int main() {
        int n;
        cin >> n;

        vector<int> preOrder(n);
        for (int i = 0; i < n; i++) {
            cin >> preOrder[i];
        }

        TreeNode* root = new TreeNode(preOrder[0]);
        TreeNode* current = root;
        for (int i = 1; i < n; i++) {
            TreeNode* node = new TreeNode(preOrder[i]);
            current->left = node;
            current = node;
        }
        current = root;
        for (int i = 1; i < n; i++) {
            TreeNode* node = new TreeNode(preOrder[i]);
            current->right = node;
            current = node;
        }

        solve(root);
        printPostOrder(maxSubtree);

        return 0;
    }
};
This code first reads the number of nodes (n), and the preorder traversal of the binary tree. Then it creates a binary tree from the preorder traversal and solves the problem by finding the subtree with maximum sum. Finally, it prints the value of the root of the subtree with maximum sum.