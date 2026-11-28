#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

Node* insert(Node* node, int data) {
    if(node == NULL) {
        return newNode(data);
    }
    if(data < node->data) {
        node->left = insert(node->left, data);
    } else {
        node->right = insert(node->right, data);
    }
    return node;
}

bool search(Node* root, int key) {
    if(root == NULL) {
        return false;
    }
    if(root->data == key) {
        return true;
    }
    if(root->data < key) {
        return search(root->right, key);
    }
    return search(root->left, key);
}

int main() {
    Node* root = NULL;
    int n, key;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int data;
        cin >> data;
        root = insert(root, data);
    }
    cin >> key;
    if(search(root, key)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
This code will take input for the number of elements (n), the elements of the Binary Search Tree (in order), and the key to search for from the user, and then it will output whether the key exists in the BST or not.