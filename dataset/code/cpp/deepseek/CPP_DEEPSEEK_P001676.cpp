Sure, here is the C++ code for the given problem:

#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left, * right;
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

void printAd(Node* root, int d, int start, int end) {
    if (root == NULL) return;
    if (d == 1) {
        if (start == 1) {
            cout << root->data << " ";
            printAd(root->right, d + 1, start + 1, end);
        } else {
            printAd(root->left, d + 1, start - 1, end);
            cout << root->data << " ";
        }
    } else {
        if (start == 1) {
            printAd(root->left, d + 1, start + 1, end);
            cout << root->data << " ";
        } else {
            printAd(root->right, d + 1, start - 1, end);
            cout << root->data << " ";
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> values;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        values.push_back(val);
    }
    queue<Node*> nodes;
    for (int i = 0; i < n; i++) {
        if (values[i] == -1) {
            nodes.push(NULL);
        } else {
            Node* node = new Node(values[i]);
            nodes.push(node);
            if (i % 2 == 0) {
                nodes.front()->left = nodes.push(new Node(values[i + 1]))->left;
                nodes.front()->right = nodes.push(new Node(values[i + 2]))->right;
            } else {
                nodes.front()->left = nodes.push(new Node(values[i + 1]))->left;
                nodes.front()->right = nodes.push(new Node(values[i + 2]))->right;
            }
            nodes.pop();
        }
    }
    printAd(nodes.front(), 1, 1, n);
    return 0;
}

This program first reads the number of nodes in the tree, and then the values of the nodes. It then creates the binary tree using the input values.

For each node, it creates a new node and adds it to the queue. If the node is not a leaf node (i.e., it has both left and right children), it also adds the left and right children to the queue.

Finally, it prints the anti-diagonal traversal of the tree.