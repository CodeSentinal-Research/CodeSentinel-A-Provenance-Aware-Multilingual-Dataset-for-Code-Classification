#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct Node {
    int data;
    int count;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->count = 0;
    node->left = node->right = nullptr;
    return node;
}

Node* insert(Node* root, int data) {
    if (root == nullptr) {
        root = newNode(data);
    } else if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

int kthSmallest(Node* root, int k) {
    if (root == nullptr) {
        return -1;
    }

    int leftSize = (root->left) ? root->left->count + 1 : 0;
    if (leftSize == k - 1) {
        return root->data;
    }
    if (leftSize >= k) {
        return kthSmallest(root->left, k);
    }
    return kthSmallest(root->right, k - leftSize - 1);
}

int main() {
    int n;
    cin >> n;

    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        root = insert(root, data);
    }

    int k;
    cin >> k;

    cout << kthSmallest(root, k) << endl;

    return 0;
}