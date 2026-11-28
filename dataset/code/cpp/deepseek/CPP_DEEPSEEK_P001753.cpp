#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void insertNode(Node* root, int value) {
    if(root == nullptr) {
        root = createNode(value);
    } else {
        if(value < root->value) {
            if(root->left == nullptr) {
                root->left = createNode(value);
            } else {
                insertNode(root->left, value);
            }
        } else {
            if(root->right == nullptr) {
                root->right = createNode(value);
            } else {
                insertNode(root->right, value);
            }
        }
    }
}

Node* findLowestInternalNode(Node* root) {
    if(root == nullptr) {
        return nullptr;
    }

    while(root->left != nullptr) {
        root = root->left;
    }

    return root;
}

int main() {
    int N;
    cin >> N;

    Node* root = nullptr;
    for(int i = 0; i < N; i++) {
        int value;
        cin >> value;
        insertNode(root, value);
    }

    Node* lowestInternalNode = findLowestInternalNode(root);

    if(lowestInternalNode != nullptr) {
        cout << lowestInternalNode->value << endl;
    } else {
        cout << "No internal node found" << endl;
    }

    return 0;
}