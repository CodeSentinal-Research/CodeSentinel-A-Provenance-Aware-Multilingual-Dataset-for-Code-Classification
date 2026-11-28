#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

int getMaxSum(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftSum = max(0, getMaxSum(root->left));
    int rightSum = max(0, getMaxSum(root->right));

    return max(leftSum + root->value, rightSum + root->value);
}

void insertNode(Node* root, int value) {
    if (root == nullptr) {
        return;
    }

    if (root->value > value) {
        if (root->left == nullptr) {
            root->left = new Node(value);
        } else {
            insertNode(root->left, value);
        }
    } else {
        if (root->right == nullptr) {
            root->right = new Node(value);
        } else {
            insertNode(root->right, value);
        }
    }
}

int main() {
    int N;
    cin >> N;

    Node* root = nullptr;
    for (int i = 0; i < N; i++) {
        int value;
        cin >> value;
        insertNode(&root, value);
    }

    cout << getMaxSum(root);

    return 0;
}
This code first reads the size of the tree from the input. It then creates a binary tree with the given node values. The `getMaxSum` function recursively calculates the maximum sum without selecting both a node and its direct child. The `insertNode` function inserts a new node into the tree.