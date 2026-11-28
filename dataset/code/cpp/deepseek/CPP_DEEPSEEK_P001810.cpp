Sure, here's the code.

#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sum = 0;

TreeNode* solve(TreeNode* root) {
    if (root == NULL)
        return NULL;
    
    TreeNode* left = solve(root->left);
    root->val += sum;
    sum = root->val;
    TreeNode* right = solve(root->right);
    
    root->left = left;
    root->right = right;
    return root;
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
    }
    
    TreeNode* root;
    root = solve(root);
    
    return 0;
}
In the code above, we are creating a TreeNode structure for the binary search tree, and then using recursive function `solve` to traverse the tree and calculate the cumulative sum of all nodes.