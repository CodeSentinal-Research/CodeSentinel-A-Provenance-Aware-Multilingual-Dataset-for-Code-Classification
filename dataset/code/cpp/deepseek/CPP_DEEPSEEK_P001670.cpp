Here is the C++ code for the problem:

#include <iostream>
#include <vector>
#include <algorithm>

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
    TreeNode* buildTree(vector<int>& preorder) {
        if (preorder.empty()) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        vector<int> left_preorder(preorder.begin() + 1, preorder.end());
        vector<int> right_preorder(preorder.begin(), preorder.end() - 1);
        root->left = buildTree(left_preorder);
        root->right = buildTree(right_preorder);
        return root;
    }
};

int main() {
    Solution sol;
    vector<int> preorder = {1, 2, 4, 8, 9, 5, 3, 6, 7};
    TreeNode* root = sol.buildTree(preorder);
    return 0;
}

This code defines a class `TreeNode` to represent the nodes of the binary tree, and a class `Solution` to solve the problem. The `buildTree` function is the main function that reconstructs the binary tree from the depth-encoded preorder traversal. It first checks if the preorder traversal is empty, and if so, returns `nullptr`. If not, it creates a new `TreeNode` with the first element of the preorder traversal as its value. Then, it recursively calls `buildTree` on the vectors of the left and right subtrees of the tree, and assigns the returned values to the `left` and `right` pointers of the root.

In the `main` function, it creates a `Solution` object and constructs a binary tree from the given preorder traversal, then prints the constructed tree.