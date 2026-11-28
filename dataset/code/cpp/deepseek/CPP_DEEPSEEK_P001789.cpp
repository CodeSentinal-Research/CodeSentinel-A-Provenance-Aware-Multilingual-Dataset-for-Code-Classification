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

Node* insert(Node* node, int data) {
    if (node == NULL) {
        return newNode(data);
    }
    if (data < node->data) {
        node->left = insert(node->left, data);
    }
    else if (data > node->data) {
        node->right = insert(node->right, data);
    }
    return node;
}

bool isBST(Node* node, Node* l = NULL, Node* r = NULL) {
    if (node == NULL) {
        return true;
    }
    if (l != NULL && node->data <= l->data) {
        return false;
    }
    if (r != NULL && node->data >= r->data) {
        return false;
    }
    return isBST(node->left, l, node) && isBST(node->right, node, r);
}

int main() {
    int N;
    cin >> N;
    Node* root = NULL;
    for (int i = 0; i < N; i++) {
        int data;
        cin >> data;
        root = insert(root, data);
    }
    bool result = isBST(root);
    cout << (result ? "YES" : "NO") << endl;
    return 0;
}