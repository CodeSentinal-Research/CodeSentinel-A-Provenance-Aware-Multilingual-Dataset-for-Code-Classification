Here's a simple C++ program that accomplishes the task:

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

void reverseLevelOrder(Node* root) {
    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if(temp->right) q.push(temp->right);
        if(temp->left) q.push(temp->left);
    }
}

int main() {
    return 0;
}

In this code, we first create a struct Node to represent each node of the binary tree. Then we define the function reverseLevelOrder that takes the root of the binary tree as input and prints the reverse level order traversal.

In the main function, you can add the code to create the tree and test the function. You need to provide the root node of the binary tree.

Note: This code assumes that the binary tree is a perfect binary tree (all levels of the tree are fully filled except the last level), as this is a common representation of binary trees. If the binary tree is not a perfect binary tree, you will need to modify the code to handle the case where there are some nodes in the last level.