Here is the C++ code to detect whether a Binary Search Tree (BST) contains a dead end:

#include <iostream>
using namespace std;

struct TreeNode {
    int key;
    TreeNode *left, *right;
    TreeNode(int key) {
        this->key = key;
        left = right = nullptr;
    }
};

TreeNode* buildTree(int arr[], int start, int end) {
    if (start > end) return nullptr;
    int mid = (start + end) / 2;
    TreeNode* root = new TreeNode(arr[mid]);
    root->left = buildTree(arr, start, mid - 1);
    root->right = buildTree(arr, mid + 1, end);
    return root;
}

bool hasDeadEnd(TreeNode* root, int key) {
    if (root == nullptr) return false;
    if (root->key == key) return true;
    if (root->key > key) return hasDeadEnd(root->left, key);
    return hasDeadEnd(root->right, key);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    TreeNode* root = buildTree(arr, 0, n - 1);
    int key;
    cin >> key;
    if (hasDeadEnd(root, key)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}

In this code, we are creating a Binary Search Tree (BST) using the given array and then searching for a key. If the key exists in the BST, the function `hasDeadEnd` returns true, otherwise false.

Note: The BST is built in the `buildTree` function. The function `buildTree` builds the BST recursively using the middle element of the array as the root.