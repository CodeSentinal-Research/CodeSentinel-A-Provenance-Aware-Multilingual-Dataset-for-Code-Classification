#include <iostream>
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
    if(node == NULL) {
        return newNode(data);
    }
    if(data < node->data) {
        node->left = insert(node->left, data);
    } else if(data > node->data) {
        node->right = insert(node->right, data);
    }
    return node;
}

int validSeq(Node* root, int arr[], int n) {
    if(root == NULL)
        return 1;

    int index = 0;
    while(root != NULL) {
        if(index == 0 || arr[index - 1] > root->data) {
            if(index == 0 || arr[index - 1] < root->data)
                return 0;
        } else {
            return 0;
        }
        index++;
        root = root->right;
    }

    root = (Node*)1;
    index = 0;
    while(root != NULL) {
        if(index == 0 || arr[index - 1] < root->data) {
            if(index == 0 || arr[index - 1] > root->data)
                return 0;
        } else {
            return 0;
        }
        index++;
        root = root->left;
    }
    return 1;
}

int solve(Node* root, int arr[], int n, int index) {
    if(index == n) {
        return validSeq(root, arr, n);
    }

    int left = solve(root, arr, n, index + 1);
    int right = solve(root, arr, n, index + 1);

    if(left == 1 || right == 1) {
        return 1;
    }

    return 0;
}

int main() {
    int n;
    cin >> n;

    Node* root = NULL;
    for(int i = 0; i < n; i++) {
        int data;
        cin >> data;
        root = insert(root, data);
    }

    int arr[n];
    for(int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    cout << solve(root, arr, n, 0) << endl;

    return 0;
}

This code first reads the number of elements in the BST, then for each element, it inserts it into the BST. It then constructs an array of integers from 1 to N in sorted order. It recursively checks the BST for each possible sequence of elements in the array and if it's valid, it increments the count.