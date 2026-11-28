Here is the C++ code for the given problem:

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node *newNode(int data) {
    Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int height(Node *node) {
    if (node == NULL)
        return 0;
    return max(height(node->left), height(node->right)) + 1;
}

int diameter(Node *node) {
    if (node == NULL)
        return 0;
    return max(height(node->left) + height(node->right) + 1,
               max(diameter(node->left), diameter(node->right)));
}

int solve(Node *root, int target) {
    if (root == NULL)
        return 0;
    if (root->data == target)
        return diameter(root);
    return max(solve(root->left, target), solve(root->right, target));
}

int main() {
    int N;
    cin >> N;
    vector<Node*> nodes;
    for (int i = 0; i < N; i++) {
        int data;
        cin >> data;
        Node *node = newNode(data);
        nodes.push_back(node);
    }
    int target;
    cin >> target;
    for (int i = 0; i < N - 1; i++) {
        int parent, child;
        cin >> parent >> child;
        nodes[parent - 1]->left = nodes[child - 1];
        nodes[parent - 1]->right = nodes[child - 1];
    }
    cout << solve(nodes[0], target) << endl;
    return 0;
}

This code first reads the number of nodes and then the nodes themselves. It then reads the parent-child relationships and connects the children to the parent in the binary tree. Finally, it calls the `solve` function with the root of the tree and the target node, and prints the result.

The `solve` function first checks if the node is NULL, in which case it returns 0. If the node is the target node, it returns the diameter of the tree. If the node is not the target node, it returns the maximum of the time it takes to burn the left and right subtrees.

The `diameter` function computes the diameter of a tree by calculating the maximum height of a subtree plus one (for the burning node).

The `height` function computes the height of a tree by calculating the maximum height of a subtree plus one (for the root node).

In the `main` function, it first reads the number of nodes and then the nodes themselves. It then reads the parent-child relationships and connects the children to the parent in the binary tree. Finally, it calls the `solve` function with the root of the tree and the target node, and prints the result.