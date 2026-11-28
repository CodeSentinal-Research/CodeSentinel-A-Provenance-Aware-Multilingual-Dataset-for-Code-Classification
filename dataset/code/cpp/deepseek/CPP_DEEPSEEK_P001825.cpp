Here is the C++ code for the problem:

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left, *right;
    Node(int data) {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

Node* newNode(int data) {
    Node* temp = new Node(data);
    return temp;
}

Node* insert(Node* root, int data) {
    if(root == nullptr) {
        root = newNode(data);
    } else if(data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

Node* buildTree(vector<int>& inorder, vector<int>& postorder) {
    Node* root = nullptr;
    for(int i : postorder) {
        root = insert(root, i);
    }
    return root;
}

Node* inorderToBST(Node* root, int& idx, int n, vector<int>& inorder) {
    if(!root) return nullptr;
    inorderToBST(root->left, idx, n, inorder);
    root->data = inorder[idx++];
    root->right = inorderToBST(root->right, idx, n, inorder);
    return root;
}

void levelOrder(Node* root) {
    if(!root) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> inorder(n), postorder(n);
    for(int& i : inorder) cin >> i;
    for(int& i : postorder) cin >> i;
    sort(inorder.begin(), inorder.end());
    Node* root = nullptr;
    int idx = 0;
    root = inorderToBST(root, idx, n, inorder);
    levelOrder(root);
    return 0;
}
In this code, we are using an inorder traversal method which preserves the sorted nature of the input data. In the `inorderToBST` function, we are traversing the inorder traversal and constructing a balanced BST. We use a global variable `idx` to keep track of the current position in the inorder traversal. In `levelOrder` function, we are printing the level order traversal of the BST.