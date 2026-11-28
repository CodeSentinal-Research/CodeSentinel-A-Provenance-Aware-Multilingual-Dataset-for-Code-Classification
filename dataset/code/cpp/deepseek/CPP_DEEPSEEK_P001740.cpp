#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left, * right;
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

Node* constructTree(int pre[], int *preIndex, int start, int end, int limit) {
    if (*preIndex >= limit) return NULL;
    Node* root = new Node(pre[*preIndex]);
    int index = -1;
    for (int i = start; i <= end; i++) {
        if (pre[*preIndex] == inorder[i]) {
            index = i;
            break;
        }
    }
    (*preIndex)++;
    if (start <= index) {
        root->left = constructTree(pre, preIndex, start, index, limit);
    }
    if (index <= end) {
        root->right = constructTree(pre, preIndex, index + 1, end, limit);
    }
    return root;
}

int main() {
    int N, pre[N];
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> pre[i];
    }
    int inorder[N];
    for (int i = 0; i < N; i++) {
        cin >> inorder[i];
    }
    int preIndex = 0;
    Node* root = constructTree(pre, &preIndex, 0, N - 1, N);
    while (root != NULL) {
        cout << "Removed node: " << root->data << endl;
        Node* temp = root;
        root = root->left;
        delete temp;
    }
    return 0;
}

The code above is a C++ program to solve the problem. It uses preorder traversal and inorder traversal to construct the binary tree. The main function is responsible for taking input for both preorder and inorder traversal, constructing the binary tree using the preorder traversal, and finally, removing all leaf nodes in rounds until the tree becomes empty. The nodes removed during each round is printed.