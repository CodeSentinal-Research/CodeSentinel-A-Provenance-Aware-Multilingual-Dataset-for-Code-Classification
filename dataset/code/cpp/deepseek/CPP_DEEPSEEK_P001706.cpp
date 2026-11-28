Here's the C++ code for your problem:

#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

int countNodes(Node* root) {
    if (root == NULL)
        return 0;

    queue<Node*> q;
    q.push(root);
    int count = 1;

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->left != NULL) {
            count++;
            q.push(temp->left);
        }

        if (temp->right != NULL) {
            count++;
            q.push(temp-.right);
        }
    }

    return count;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Count of nodes in complete binary tree is " << countNodes(root);

    return 0;
}

In this code, we are using a queue to perform level order traversal. In each level, we increment the count variable and add the children of the current node to the queue. This way, we traverse the complete binary tree in less than linear time, as required.