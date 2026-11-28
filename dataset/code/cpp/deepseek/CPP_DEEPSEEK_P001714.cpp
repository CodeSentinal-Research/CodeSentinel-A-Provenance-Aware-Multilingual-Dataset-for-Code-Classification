#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

int countHalfNodes(Node* root) {
    if (root == NULL) return 0;

    int count = 0;
    if ((root->left != NULL) && (root->right != NULL)) {
        if ((root->left->left == NULL) && (root->left->right == NULL) &&
            (root->right->left == NULL) && (root->right->right == NULL))
            count = 1;
        else
            count = countHalfNodes(root->left) + countHalfNodes(root->right);
    }

    return count;
}

int main() {
    Node *root = new Node();

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int data;
        cin >> data;
    }

    cout << countHalfNodes(root);

    return 0;
}