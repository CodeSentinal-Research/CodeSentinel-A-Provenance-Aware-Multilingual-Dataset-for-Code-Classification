#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int height(Node* node) {
    if (node == NULL) {
        return 0;
    }
    else {
        int lheight = height(node->left);
        int rheight = height(node->right);
        if (lheight > rheight) {
            return lheight + 1;
        } else {
            return rheight + 1;
        }
    }
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    cout << "Height of the binary tree is: " << height(root) << endl;
    return 0;
}