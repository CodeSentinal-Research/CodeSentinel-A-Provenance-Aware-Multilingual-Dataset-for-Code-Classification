Here is the C++ code for the given problem:

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

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        inorderTraversal(root);
    }

    bool hasNext() const {
        return !nodes.empty();
    }

    int next() {
        int val = nodes.back();
        nodes.pop_back();
        return val;
    }

private:
    void inorderTraversal(TreeNode* root) {
        if (root) {
            inorderTraversal(root->left);
            nodes.push_back(root->val);
            inorderTraversal(root->right);
        }
    }

    vector<int> nodes;
};

class Solution {
public:
    TreeNode* flatten(TreeNode* root) {
        if (!root) return nullptr;
        TreeNode* left = flatten(root->left);
        TreeNode* right = flatten(root->right);
        root->left = nullptr;
        root->right = nullptr;
        TreeNode* node = root;
        while (node->right) node = node->right;
        node->right = right;
        if (left) {
            node->right->left = left;
        }
        return left ? left : root;
    }

    void flatten(TreeNode* root, vector<int>& sequence) {
        if (!root) return;
        flatten(root->left, sequence);
        flatten(root->right, sequence);
        sequence.push_back(root->val);
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        int maxIndex = max_element(nums.begin(), nums.end()) - nums.begin();
        TreeNode* root = new TreeNode(nums[maxIndex]);
        vector<int> leftNums(nums.begin(), nums.begin() + maxIndex);
        vector<int> rightNums(nums.begin() + maxIndex + 1, nums.end());
        root->left = constructMaximumBinaryTree(leftNums);
        root->right = constructMaximumBinaryTree(rightNums);
        return root;
    }

    vector<int> constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root = constructMaximumBinaryTree(nums);
        vector<int> sequence;
        flatten(root, sequence);
        return sequence;
    }
};

In this code, we have defined a `TreeNode` structure for the binary tree node, and a `BSTIterator` class to iterate over the binary search tree in order. 

The `Solution` class has three methods: `flatten`, `constructMaximumBinaryTree` and `constructMaximumBinaryTree`. The `flatten` method flattens a binary tree into a sequence, and the `constructMaximumBinaryTree` method constructs a maximum binary tree from a given sequence. 

The `constructMaximumBinaryTree` method first constructs a maximum binary tree, then flattens it into a sequence, and returns the sequence. 

Please note that this code assumes that the input is a valid binary search tree, and the tree is not empty. If the input might be invalid, you should add input validation code.