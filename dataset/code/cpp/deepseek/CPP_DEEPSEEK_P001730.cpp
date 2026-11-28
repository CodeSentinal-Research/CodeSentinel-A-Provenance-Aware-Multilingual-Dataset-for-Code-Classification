Here is a C++ code snippet to convert a binary tree into a circular doubly linked list.

#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

Node* sortedArrayToBST(int arr[], int start, int end) {
    if (start > end) {
        return NULL;
    }
    int mid = (start + end) / 2;
    Node *root = new Node(arr[mid]);
    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);
    return root;
}

void printList(Node *head) {
    if (head == NULL) {
        return;
    }
    cout << head->data << " ";
    printList(head->right);
}

Node *flatten(Node *root) {
    if (root == NULL) {
        return NULL;
    }
    Node *a = flatten(root->left);
    Node *b = flatten(root->right);
    root->left = root->right = NULL;
    Node *head = root;
    while (head->right != NULL) {
        head = head->right;
    }
    head->right = root;
    root->left = head;
    return a ? a->left : b;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = sortedArrayToBST(arr, 0, n - 1);
    root = flatten(root);
    printList(root);
    return 0;
}

In this code:

1. We first define a structure for a binary tree node:

struct Node {
    int data;
    Node *left, *right;
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

2. We then define a function to convert a sorted array to a binary search tree. We use the middle element of the array as the root of the tree, and recursively construct the left and right subtrees.

3. We define a function to print a circular doubly linked list. We do this by printing the data of the nodes in the list, and then recursively print the right sublist.

4. In the `main` function, we first create a sorted array, convert it to a binary search tree, and flatten the tree into a circular doubly linked list. We then print the list.