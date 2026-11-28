Here is the C++ code that solves the problem:

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int val) : val(val), left(NULL), right(NULL) {}
};

void findMinAtEachLevel(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int minVal = q.front()->val;
        cout << minVal << ": ";
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            minVal = min(minVal, node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << minVal << " ";
    }
}

int main() {
    int n;
    cin >> n;
    Node* nodes[n+1];
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        nodes[i] = new Node(val);
        if (i > 1) {
            nodes[i-1]->left = nodes[i];
            nodes[i]->parent = nodes[i-1];
        }
        if (i < n) {
            cin >> val;
            nodes[i]->right = nodes[i+1];
            nodes[i+1]->parent = nodes[i];
        }
    }
    Node* root = nodes[1];
    findMinAtEachLevel(root);
    return 0;
}

This code first reads the number of nodes and the node values. It then creates the binary tree and finds the minimum value at each level. The `findMinAtEachLevel` function uses a queue to perform level order traversal of the tree. For each level, it pushes all the nodes into the queue, then pops out the minimum value at each iteration and prints it out. This process is repeated until the queue is empty.