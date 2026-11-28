#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        if (root == NULL) return NULL;
        
        root->val += bstToGst(root->right) + bstToGst(root->left);
        
        return root;
    }
};

int main() {
    Solution solution;
    

    return 0;
}
This code defines a TreeNode structure and a Solution class that contains a function to convert a Binary Search Tree into a Greater Sum Tree.

The function `bstToGst(TreeNode* root)` is a recursive function that traverses the BST in a post-order (right, left, root) traversal. For each node, it adds the sum of all keys greater than or equal to the node's key to the node's value.

Please note that in the main function, you need to handle input for the number of nodes and the values of the nodes. This can be done using a priority queue or similar data structure. Also, please ensure to free the allocated memory when you're done with your tree.

Please replace the comment in the main function with the appropriate input handling code.