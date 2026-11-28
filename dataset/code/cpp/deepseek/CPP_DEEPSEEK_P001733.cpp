#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->value = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node* insertNode(Node* root, int value) {
    if (root == nullptr) {
        root = createNode(value);
    } else {
        if (root->value < value) {
            root->right = insertNode(root->right, value);
        } else {
            root->left = insertNode(root->left, value);
        }
    }
    return root;
}

bool isSumTree(Node* root, int& sum) {
    if (root == nullptr) {
        return true;
    }

    int leftSum = 0;
    if (isSumTree(root->left, leftSum)) {
        int rightSum = 0;
        if (isSumTree(root->right, rightSum)) {
            sum = root->value + leftSum + rightSum;
            return (sum == root->value);
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        root = insertNode(root, value);
    }

    int sum = 0;
    if (isSumTree(root, sum)) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}