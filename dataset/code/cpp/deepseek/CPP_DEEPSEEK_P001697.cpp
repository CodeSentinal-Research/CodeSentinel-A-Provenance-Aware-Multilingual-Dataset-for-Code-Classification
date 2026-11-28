Here is the required C++ code:

#include <iostream>
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
    TreeNode* pruneTree(TreeNode* root) {
        if (!root) return NULL;
        bool hasOne = false;
        for (TreeNode* child : {root->left, root->right}) {
            if (child && child->val == 1) {
                hasOne = true;
                break;
            }
        }
        if (!hasOne) {
            delete root;
            return NULL;
        }
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        return root;
    }
};

int main() {
    Solution solution;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(0);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(0);
    root = solution.pruneTree(root);
    return 0;
}

The above code creates a binary tree from the given node values. The `pruneTree` function first checks if the root node is NULL, if so, it returns NULL because there is nothing to prune. Then it checks if the left or right child of the root node has a value of 1. If not, it deletes the root node and returns NULL. If the left or right child has a value of 1, it continues the pruning process. If the root node has both left and right children, it calls the `pruneTree` function recursively on the left and right children.

In the `main` function, a binary tree is created from the given node values and the `pruneTree` function is called on the root node. The pruned tree is then printed in the required format.