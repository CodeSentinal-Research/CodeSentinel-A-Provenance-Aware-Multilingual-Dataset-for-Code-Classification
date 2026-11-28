#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node* insert(Node* root, int data) {
    if(root == NULL) {
        root = newNode(data);
    } else if(data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

int findMax(Node* root) {
    if(root == NULL) {
        return INT_MIN;
    }
    if(root->right == NULL) {
        return root->data;
    }
    return findMax(root->right);
}

int main() {
    int n;
    cin >> n;
    Node* root = NULL;
    while(n--) {
        int data;
        cin >> data;
        root = insert(root, data);
    }
    cout << findMax(root);
    return 0;
}