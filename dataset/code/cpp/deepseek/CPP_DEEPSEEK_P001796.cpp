Here is a simple C++ solution for the problem:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

Node* constructBST(vector<int> &preorder, int start, int end) {
    if (start > end) {
        return nullptr;
    }
    int mid = start;
    for (int i = start + 1; i <= end; i++) {
        if (preorder[i] < preorder[start]) {
            mid = i;
        }
    }
    Node* root = new Node(preorder[start]);
    root->left = constructBST(preorder, start + 1, mid - 1);
    root->right = constructBST(preorder, mid + 1, end);
    return root;
}

int main() {
    int n;
    cin >> n;
    vector<int> preorder(n);
    for (int i = 0; i < n; i++) {
        cin >> preorder[i];
    }
    Node* root = constructBST(preorder, 0, n - 1);
    return 0;
}

This code first reads the number of elements in the input, then reads the preorder traversal. The `constructBST` function is then called with the preorder traversal, the start and end indices of the range of elements, and the middle index of the range. This function constructs a BST from the given preorder traversal, starting from the first element and ending at the middle element, and then recursively calling itself for the left and right subtrees.