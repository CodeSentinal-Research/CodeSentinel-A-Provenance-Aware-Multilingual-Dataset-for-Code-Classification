#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
};

Node* newNode(int item) {
    Node* temp = new Node();
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

Node* insert(Node* Node, int key) {
    if (Node == NULL) return newNode(key);
    if (key < Node->key)
        Node->left = insert(Node->left, key);
    else if (key > Node->key)
        Node->right = insert(Node->right, key);
    return Node;
}

void inorder(Node* node) {
    if (node == NULL)
        return;
    inorder(node->left);
    cout << node->key << " ";
    inorder(node->right);
}

int main() {
    Node* root = NULL;
    int keys[] = {50, 30, 20, 40, 70, 60, 80};
    int n = sizeof(keys) / sizeof(keys[0]);
    for (int i = 0; i < n; i++)
        root = insert(root, keys[i]);
    inorder(root);
    return 0;
}