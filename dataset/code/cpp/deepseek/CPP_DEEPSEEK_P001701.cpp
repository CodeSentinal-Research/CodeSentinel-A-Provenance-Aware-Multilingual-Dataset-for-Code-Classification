#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int value;
    Node *left, *right;
};

Node* createNode(int value) {
    Node* node = new Node;
    node->value = value;
    node->left = node->right = NULL;
    return node;
}

Node* insertNode(Node* root, int value) {
    if (root == NULL) {
        root = createNode(value);
    } else {
        if (value < root->value) {
            root->left = insertNode(root->left, value);
        } else {
            root->right = insertNode(root->right, value);
        }
    }
    return root;
}

void replaceWithSum(Node* root) {
    if (root == NULL) {
        return;
    }

    int leftSum = root->left ? root->left->value : 0;
    int rightSum = root->right ? root->right->value : 0;

    root->value = leftSum + rightSum;

    replaceWithSum(root->left);
    replaceWithSum(root->right);
}

int main() {
    int n;
    cin >> n;

    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        root = insertNode(root, value);
    }

    replaceWithSum(root);

    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        cout << node->value << ' ';
        if (node->left) {
            q.push(node->left);
        }
        if (node->right) {
            q.push(node->right);
        }
    }

    return 0;
}