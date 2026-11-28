Here is the code for your problem:

#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) : key(k), left(NULL), right(NULL) {}
};

void deleteKey(Node** root, int key) {
    if (*root == NULL)
        return;

    if ((*root)->key > key)
        deleteKey(&((*root)->left), key);
    else if ((*root)->key < key)
        deleteKey(&((*root)->right), key);
    else {
        if ((*root)->left == NULL) {
            Node* temp = (*root);
            (*root) = (*root)->right;
            delete temp;
        }
        else if ((*root)->right == NULL) {
            Node* temp = (*root);
            (*root) = (*root)->left;
            delete temp;
        }
        else {
            Node* temp = (*root)->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            (*root)->key = temp->key;
            deleteKey(&((*root)->right), temp->key);
        }
    }
}

Node* insert(Node* node, int key) {
    if (node == NULL) {
        return new Node(key);
    }
    if (key < node->key) {
        node->left = insert(node->left, key);
    }
    else if (key > node->key) {
        node->right = insert(node->right, key);
    }
    return node;
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
    int n, key;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> key;
        root = insert(root, key);
    }
    cin >> key;
    deleteKey(&root, key);
    inorder(root);
    return 0;
}

In this code, we use the Binary Search Tree (BST) data structure. For each operation, we check if the key exists in the tree. If the key is present in the tree, we delete it. If not, we insert the key into the tree. Finally, we print the inorder traversal of the modified tree.