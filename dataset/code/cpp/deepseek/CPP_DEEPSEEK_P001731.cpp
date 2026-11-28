Here is a simple C++ solution that uses recursive inorder traversal to convert a binary tree into a threaded binary tree. 

#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* thread;
};

Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = temp->thread = nullptr;
    return temp;
}

Node* buildTree(int postOrder[], int start, int end) {
    if (start > end) return nullptr;
    Node* root = newNode(postOrder[end]);
    int i = start;
    while (i < end && postOrder[i] < postOrder[end]) ++i;
    root->right = buildTree(postOrder, i + 1, end - 1);
    if (start < i) {
        root->left = buildTree(postOrder, start, i - 1);
    }
    return root;
}

Node* convert(Node* root) {
    if (!root) return nullptr;
    Node* right = convert(root->right);
    if (right) {
        while (right->thread) right = right->thread;
        right->right = root;
        root->thread = right;
    }
    root->right = right;
    if (root->left) {
        Node* left = convert(root->left);
        while (left->thread) left = left->thread;
        left->thread = root;
        root->thread = left;
    }
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    int postOrder[] = {1, 2, 4, 8, 5, 3, 6, 7};
    int n = sizeof(postOrder) / sizeof(postOrder[0]);
    Node* root = buildTree(postOrder, 0, n - 1);
    root = convert(root);
    inorder(root);
    return 0;
}

In this code, we first build the binary tree from the postorder array. Then we convert the binary tree into a threaded binary tree. The inorder traversal is used to get the inorder successor for each node. The threaded binary tree is built by modifying the right pointer of each node to the inorder successor node.