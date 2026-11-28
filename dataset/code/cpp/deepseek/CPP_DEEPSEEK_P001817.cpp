#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int data) : data(data), left(NULL), right(NULL) {}
};

void insert(Node* &root, int data) {
    if (!root) root = new Node(data);
    else if (data < root->data) insert(root->left, data);
    else insert(root->right, data);
}

Node* build(int N, vector<int> &a) {
    Node *root = NULL;
    for (int i : a) insert(root, i);
    return root;
}

int ceil(Node* root, int key) {
    if (root == NULL) return -1;
    if (root->data <= key) return root->data;
    int ceilVal = ceil(root->right, key);
    if (ceilVal != -1) return ceilVal;
    return root->data;
}

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    int key;
    cin >> key;
    Node *root = build(N, a);
    cout << ceil(root, key) << "\n";
    return 0;
}
This code firstly declares a Node struct and a insert function to insert a new node in the BST. The build function is used to construct the BST from the given array. The ceil function is a recursive function to find the smallest key greater than or equal to X in the BST. If no such value exists, it returns -1. The main function handles the input and output.