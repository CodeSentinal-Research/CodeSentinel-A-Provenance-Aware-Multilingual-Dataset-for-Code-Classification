#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

bool isFullBT(Node* root) {
    if (root == NULL)
        return true;

    if (root->left == NULL || root->right == NULL)
        return false;

    return (isFullBT(root->left) && isFullBT(root->right));
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << (isFullBT(root) ? "YES" : "NO");

    return 0;
}
This C++ code first creates a binary tree with 5 nodes. Then it calls the isFullBT function to check if the tree is full. The function isFullBT recursively checks if all nodes in the binary tree have either zero or two children. If all nodes meet the condition, it returns true. If not, it returns false.