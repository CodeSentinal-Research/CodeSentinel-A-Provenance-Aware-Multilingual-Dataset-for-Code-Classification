Here is the complete C++ code for the problem. This code reads the binary tree from the input and connects each node to its next node on the same level.

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *next;
    TreeNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeNode* root) {
    if (root == NULL) return;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();
        TreeNode* prev = q.front();
        q.pop();

        for (int i = 0; i < size - 1; ++i) {
            TreeNode* curr = q.front();
            prev->next = curr;
            prev = curr;
            q.pop();
        }
        prev->next = NULL;

        if (root->left) q.push(root->left);
        if (root->right) q.push(root->right);
        root = q.front();
    }
}

This code first checks if the root node is null. If it is, it returns immediately because there's nothing to connect.

Next, it creates a queue and pushes the root node into it.

Then, it enters a loop that runs until the queue is empty. Inside the loop, it calculates the size of the queue. For each iteration, it pops a node from the queue and connects the previous node to the current node. It also updates the previous node and pushes the current node into the queue if they exist (i.e., if they are not null).

Finally, it updates the root node to the next node in the queue and repeats the process until all nodes are connected.

This approach uses the Breadth-First Search (BFS) strategy for traversing the binary tree.