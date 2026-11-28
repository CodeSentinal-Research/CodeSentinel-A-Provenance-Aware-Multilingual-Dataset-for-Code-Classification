Here's the complete C++ code for the problem:

#include <iostream>
#include <queue>

using namespace std;

struct Node {
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

Node* insert(Node* node, int data) {
    if(node == NULL)
        return newNode(data);
    else if(data <= node->data)
        node->left = insert(node->left, data);
    else
        node->right = insert(node->right, data);
    return node;
}

Node* constructBST(Node* node, int arr[], int start, int end) {
    if(start > end)
        return node;
    int mid = (start + end) / 2;
    node = insert(node, arr[mid]);
    node = constructBST(node, arr, start, mid - 1);
    node = constructBST(node, arr, mid + 1, end);
    return node;
}

void printDLL(Node* head) {
    Node* node = head;
    do {
        cout << node->data << " ";
        node = node->right;
    } while(node != head);
    cout << endl;
}

Node* constructDLL(int arr[], int n) {
    Node* node = NULL;
    node = constructBST(node, arr, 0, n - 1);
    Node* head = node;
    while(node->left)
        node = node->left;
    node->left = head;
    head->right = node;
    return head;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* head = constructDLL(arr, n);
    printDLL(head);
    return 0;
}

This code first constructs a binary search tree from the given array and then converts it into a sorted circular doubly linked list.