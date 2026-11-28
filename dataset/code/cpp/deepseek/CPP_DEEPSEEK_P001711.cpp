Here is the C++ code for the problem:

#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

bool isSumProperty(Node* root) {
    int total = 0;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* node = q.front();
        q.pop();

        if (node->left) {
            q.push(node->left);
            total += node->left->data;
        }

        if (node->right) {
            q.push(node->right);
            total += node->right->data;
        }
    }

    return total == root->data;
}

int main() {
    Node* root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(8);
    root->left->right = new Node(12);
    root->right->left = new Node(25);
    root->right->right = new Node(30);

    if (isSumProperty(root)) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}

This code first declares a Node structure that contains data, left and right pointers. It then declares a function `isSumProperty` that takes a root of a binary tree and checks if every non-leaf node has a value equal to the sum of the values of its immediate children. It uses a Breadth-First Search (BFS) approach to traverse the tree.

The main function creates a binary tree and calls `isSumProperty` to check if the tree satisfies the children sum property.

Please note that this code assumes that the tree is given as a binary tree in a pre-order traversal (i.e., the root is visited before its children), and that the tree does not contain any duplicate values.