#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left, *right;
};

Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node* constructTree(int pre[], int *preIndex, int start, int end) {
    if (start > end) return NULL;
    Node* temp = newNode(pre[*preIndex]);
    (*preIndex)++;
    if (start == end) return temp;
    temp->left = constructTree(pre, preIndex, start, temp->data - 1);
    temp->right = constructTree(pre, preIndex, temp->data + 1, end);
    return temp;
}

void mirror(Node* node) {
    if (node == NULL) return;
    mirror(node->left);
    mirror(node->right);
    swap(node->left, node->right);
}

void inorder(Node* node) {
    if (node == NULL) return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

int main() {
    int pre[1000];
    int index = 0;
    int data;
    int start, end;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
    }
    Node* root = constructTree(pre, &index, 0, pre[0] - 1);
    mirror(root);
    inorder(root);
    return 0;
}