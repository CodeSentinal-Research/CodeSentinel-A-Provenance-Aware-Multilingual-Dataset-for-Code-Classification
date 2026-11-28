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
    temp->left = temp->right = nullptr;
    return temp;
}

Node* insert(Node* root, int data) {
    if (root == nullptr) {
        root = newNode(data);
        return root;
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }
    return root;
}

int countInternalNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->left == nullptr || root->right == nullptr) {
        return 0;
    }
    return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
}

int main() {
    Node* root = nullptr;
    int N;
    cin >> N;
    while (N-- > 0) {
        int data;
        cin >> data;
        root = insert(root, data);
    }
    cout << countInternalNodes(root) << endl;
    return 0;
}