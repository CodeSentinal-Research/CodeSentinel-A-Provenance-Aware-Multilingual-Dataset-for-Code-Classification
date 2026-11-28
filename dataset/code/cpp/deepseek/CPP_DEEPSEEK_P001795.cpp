#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

Node* insertLevelOrder(int arr[], int i, int n) {
    if (i < n) {
        Node *root = new Node(arr[i]);
        root->left = insertLevelOrder(arr, 2 * i + 1, n);
        root->right = insertLevelOrder(arr, 2 * i + 2, n);
        return root;
    }
    return NULL;
}

void printInorder(Node* node) {
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = insertLevelOrder(arr, 0, n);
    printInorder(root);
    return 0;
}
This code constructs a height-balanced Binary Search Tree from a sorted array. The input array is defined by the variable arr. The function insertLevelOrder() is used to construct the BST. It takes in the array, current index (i), and the number of elements in the array as parameters. If the current index is less than the number of elements, it constructs a new node with the value at the current index in the array, and recursively calls itself on the left and right children. If the current index is larger than or equal to the number of elements, it returns NULL. The function printInorder() is used to print the inorder traversal of the BST.