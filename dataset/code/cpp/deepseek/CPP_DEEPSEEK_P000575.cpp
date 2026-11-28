Here is a C++ code that solves the problem:

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int widthOfBinaryTree(TreeNode* root) {
    if (root == nullptr) return 0;
    
    queue<pair<TreeNode*, long long>> q; 
    q.push({root, 0});
    
    long long minPos = 0, maxPos = 0, levelSize = 0, levelWidth = 0;
    
    while (!q.empty()) {
        pair<TreeNode*, long long> p = q.front(); q.pop();
        
        long long pos = p.second;
        TreeNode* node = p.first;
        
        if (levelSize == 0) {
            minPos = pos;
        }
        
        levelSize++;
        levelWidth = pos - minPos + 1;
        
        if (node->left) {
            q.push({node->left, pos * 2 + 1});
        }
        
        if (node->right) {
            q.push({node->right, pos * 2 + 2});
        }
    }
    
    return levelWidth;
}

This code uses a Breadth-First Search (BFS) approach to find the maximum width of the binary tree. The queue is used to keep track of nodes and their positions in the binary tree. The level size is incremented each time we process a node, and the width of the current level is updated with the current position.

To handle input and output, we need to provide the function `widthOfBinaryTree` with a `TreeNode` as an argument, and then call this function with the root of the binary tree. The function will then return the maximum width of the binary tree.