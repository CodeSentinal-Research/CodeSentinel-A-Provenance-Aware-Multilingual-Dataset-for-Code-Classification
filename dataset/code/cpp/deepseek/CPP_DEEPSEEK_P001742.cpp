#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

void printLeaves(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);

        if (!temp->left && !temp->right) {
            cout << temp->data << " ";
        }
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    printLeaves(root);

    return 0;
}

This C++ code creates a binary tree from a given input. It then prints the leaf nodes from right to left. The `printLeaves` function uses a breadth-first search (BFS) to traverse the tree, print the leaf nodes in the order they were visited.