Here is a simple C++ program that implements the problem using a binary tree and the concept of binary tree depth-first search.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int findLeftMostDeepestNode(TreeNode* root) {
    if (root == NULL) return -1;  

    queue<TreeNode*> nodes;  
    nodes.push(root);

    TreeNode* curr;  
    TreeNode* leftMostNode = root;  

    while (!nodes.empty()) {
        int size = nodes.size();

        for (int i = 0; i < size; i++) {
            curr = nodes.front();
            nodes.pop();

            if (curr->val < leftMostNode->val) {
                leftMostNode = curr;
            }

            if (curr->left != NULL) {
                nodes.push(curr->left);
            }
            if (curr->right != NULL) {
                nodes.push(curr->right);
            }
        }
    }

    return leftMostNode->val;  
}

int main() {

    return 0;
}

The function `findLeftMostDeepestNode` uses a Breadth-First Search (BFS) approach to find the leftmost node at the maximum depth. It starts from the root and goes level by level, updating the `leftMostNode` as it goes deeper.

Please note, you need to provide a function to build the tree and fill the data for testing.