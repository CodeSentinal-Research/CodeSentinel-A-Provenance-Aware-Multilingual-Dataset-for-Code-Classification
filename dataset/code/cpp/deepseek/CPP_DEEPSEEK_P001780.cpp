Here is a C++ solution for the problem. The main idea is to use Depth-First Search (DFS) to traverse the binary tree and find the longest decreasing path.

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
    int longestDecreasingPath(TreeNode* root) {
        if (!root) return 0;
        dfs(root, 1);
        return maxAns;
    }

private:
    int maxAns = 0;

    int dfs(TreeNode* node, int path) {
        if (!node) return 0;
        int left = dfs(node->left, node->left ? path + 1 : 1);
        int right = dfs(node->right, node->right ? path + 1 : 1);
        maxAns = max(maxAns, left + right);
        return max(0, left > right ? left : right) + 1;
    }
};

The `longestDecreasingPath` function is the entry point of the program. It calls the `dfs` function to traverse the binary tree from the root node.

The `dfs` function returns the length of the longest decreasing path of the current node. If the node is null, it returns 0. The function checks if both left and right child of the node exist, if yes, it increments the path by 1, else it sets the path to 1. Then it computes the longest path of the current node by comparing the longest path of its left and right children and adding 1 to it. If the longest path of the left child is greater than the right child, it returns the longest path of the left child, else it returns the longest path of the right child.

The `maxAns` variable is used to store the longest decreasing path found so far.