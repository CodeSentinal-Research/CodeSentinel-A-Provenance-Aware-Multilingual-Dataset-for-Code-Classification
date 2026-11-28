#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int data) : data(data), left(NULL), right(NULL) {}
};

Node* newNode(int data) {
    return new Node(data);
}

int height(Node* root) {
    if (root == NULL) return 0;
    return max(height(root->left), height(root->right)) + 1;
}

int main() {
    int N;
    cin >> N;
    vector<Node*> nodes(N);
    for (int i = 0; i < N; i++) {
        int parent, leftChild, rightChild;
        cin >> parent >> leftChild >> rightChild;
        nodes[i] = newNode(i + 1);
        if (leftChild != -1) nodes[i]->left = nodes[leftChild];
        if (rightChild != -1) nodes[i]->right = nodes[rightChild];
    }
    for (int i = 0; i < N; i++) {
        cout << height(nodes[i]) << endl;
    }
    return 0;
}