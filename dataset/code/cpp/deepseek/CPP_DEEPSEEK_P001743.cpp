Here is the C++ code for the problem:

#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node* buildTree(Node* root) {
    int data;
    cin >> data;

    if (data == -1)
        return NULL;

    root = newNode(data);
    root->left = buildTree(root->left);
    root->right = buildTree(root->right);

    return root;
}

int getSize(Node* root) {
    if (root == NULL)
        return 0;

    return 1 + getSize(root->left) + getSize(root->right);
}

int firstNonFullNode(Node* root) {
    int size = getSize(root);
    int level = 1;
    queue<pair<Node*, int>> q;
    q.push({root, level});

    while (!q.empty()) {
        pair<Node*, int> p = q.front();
        q.pop();

        if (p.second == level && p.first->left != NULL && p.first->right != NULL) {
            return p.first->data;
        }

        if (p.first->left)
            q.push({p.first->left, level + 1});

        if (p.first->right)
            q.push({p.first->right, level + 1});
    }

    return -1;
}

int main() {
    Node* root;
    root = buildTree(root);
    cout << firstNonFullNode(root) << endl;

    return 0;
}

This code constructs a binary tree from the input and uses a level order traversal to find the first node that does not have exactly two children. The `firstNonFullNode` function uses a queue to perform the traversal and check each node's data. If a node is found to have exactly two children, it is returned. If no such node is found after traversing all nodes, -1 is returned.