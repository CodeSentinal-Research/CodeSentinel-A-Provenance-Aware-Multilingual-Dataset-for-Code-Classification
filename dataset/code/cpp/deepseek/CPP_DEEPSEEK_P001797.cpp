Here is the C++ code to construct a Binary Search Tree from the Postorder Traversal:

#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
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

Node* constructTree(vector<int> &postorder, int start, int end, int &index) {
    if (start > end) {
        return NULL;
    }
    Node* node = newNode(postorder[index]);
    index--;
    if (start == end) {
        return node;
    }
    int i = end;
    while (i >= start && postorder[i] > node->data) {
        i--;
    }
    node->right = constructTree(postorder, i + 1, end, index);
    node->left = constructTree(postorder, start, i, index);
    return node;
}

void preOrder(Node* node) {
    if (node == NULL) {
        return;
    }
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

int main() {
    int n;
    cin >> n;
    vector<int> postorder(n);
    for (int i = 0; i < n; i++) {
        cin >> postorder[i];
    }
    int index = n - 1;
    Node* root = constructTree(postorder, 0, n - 1, index);
    preOrder(root);
    return 0;
}

This code first reads the number of nodes in the tree and the postorder traversal. It then constructs the tree using the postorder traversal and prints the preorder traversal of the reconstructed tree.