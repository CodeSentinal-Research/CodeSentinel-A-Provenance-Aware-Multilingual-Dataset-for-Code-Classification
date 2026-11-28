#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* newNode(int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node* insert(Node* node, int data) {
    if (node == NULL) {
        return newNode(data);
    }
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }
    return node;
}

bool isLeaf(Node* root) {
    return (root->left == NULL && root->right == NULL);
}

int countDeadEnds(Node* root) {
    if (!root) return 0;
    int count = 0;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* node = q.front(); q.pop();
        if (isLeaf(node) && (node->left || node->right)) {
            count++;
        } else {
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return count;
}

int main() {
    int N;
    cin >> N;
    Node* root = NULL;
    for (int i = 0; i < N; i++) {
        int data;
        cin >> data;
        root = insert(root, data);
    }
    cout << countDeadEnds(root) << endl;
    return 0;
}