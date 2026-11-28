#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* left, *right;
};

Node* newNode(int data) {
    Node* temp = new Node;
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

int findDistance(Node* root, int a, int b) {
    int d1 = -1, d2 = -1, h1 = -1, h2 = -1;
    queue<pair<Node*, int>> q1, q2;
    q1.push({root, 0});
    q2.push({root, 0});
    while (!q1.empty()) {
        auto x = q1.front(); q1.pop();
        if (x.first->data == a && h1 == -1) {
            d1 = x.second;
            h1 = x.first->data;
        } else if (x.first->data == a) {
            h1 = x.first->data;
        } else if (x.first->data == b && h2 == -1) {
            d2 = x.second;
            h2 = x.first->data;
        } else if (x.first->data == b) {
            h2 = x.first->data;
        }
        if (x.first->left) q1.push({x.first->left, x.second + 1});
        if (x.first->right) q1.push({x.first->right, x.second + 1});
    }
    while (!q2.empty()) {
        auto x = q2.front(); q2.pop();
        if (x.first->data == a && h1 != x.first->data && d1 != -1 && h2 != x.first->data && d2 != -1) {
            d2 = x.second - d1;
            return max(d1, d2);
        } else if (x.first->data == a) {
            h1 = x.first->data;
        } else if (x.first->data == b && h2 != x.first->data && d2 != -1) {
            d2 = x.second;
            h2 = x.first->data;
        } else if (x.first->data == b) {
            h2 = x.first->data;
        }
        if (x.first->left) q2.push({x.first->left, x.second + 1});
        if (x.first->right) q2.push({x.first->right, x.second + 1});
    }
    return -1;
}

int main() {
    Node* root = NULL;
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        root = insert(root, data);
    }
    cin >> a >> b;
    cout << findDistance(root, a, b);
    return 0;
}