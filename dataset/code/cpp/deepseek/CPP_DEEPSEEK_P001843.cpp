#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int data) {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

Node* insert(Node* node, int data) {
    if(node == nullptr) {
        return new Node(data);
    }
    if(data < node->data) {
        node->left = insert(node->left, data);
    } else {
        node->right = insert(node->right, data);
    }
    return node;
}

void printInOrder(Node* node) {
    if(node == nullptr) {
        return;
    }
    printInOrder(node->left);
    cout << node->data << ' ';
    printInOrder(node->right);
}

Node* sortedListToBST(vector<int>& arr, int start, int end) {
    if(start > end) {
        return nullptr;
    }
    int mid = (start + end) / 2;
    Node* node = new Node(arr[mid]);
    node->left = sortedListToBST(arr, start, mid - 1);
    node->right = sortedListToBST(arr, mid + 1, end);
    return node;
}

Node* sortedListToBalancedBST(vector<int> arr) {
    int n = arr.size();
    return sortedListToBST(arr, 0, n - 1);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    Node* root = sortedListToBalancedBST(arr);
    printInOrder(root);
    return 0;
}
This program firstly reads the size of the input linked list, then reads the elements of the linked list. The sorted linked list is converted to a balanced BST using the function sortedListToBalancedBST. Finally, the BST is printed in InOrder traversal.