Here is the code for the given problem:

#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left, * right;
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

Node* insert(Node* root, int data) {
    if (root == NULL) {
        return new Node(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

bool isSubtree(Node* root1, Node* root2) {
    if (root2 == NULL) return true;
    if (root1 == NULL) return false;
    return (isIdentical(root1, root2) && isSubTree(root1->left, root2) && isSubTree(root1->right, root2));
}

bool isIdentical(Node* a, Node* b) {
    if (a == NULL && b == NULL) return true;
    if (a == NULL || b == NULL) return false;
    return (a->data == b->data && isIdentical(a->left, b->left) && isIdentical(a->right, b->right));
}

int main() {
    int N;
    cin >> N;
    Node* root1 = NULL;
    while (N--) {
        int data;
        cin >> data;
        root1 = insert(root1, data);
    }
    int M;
    cin >> M;
    Node* root2 = NULL;
    while (M--) {
        int data;
        cin >> data;
        root2 = insert(root2, data);
    }
    cout << (isSubTree(root1, root2) ? "YES" : "NO");
    return 0;
}

In this code, we first insert nodes into the first BST. Then, we insert nodes into the second BST. After that, we check if the second BST is a subtree of the first BST. The `isSubTree` function checks if the second BST is a subtree of the first BST, and the `isIdentical` function checks if two BSTs are identical. If both of them return true, it means the second BST is a subtree of the first BST.