Here is the C++ code for the problem:

#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

bool isBalanced(Node* root) {
    if (root == nullptr) {
        return true;
    }

    int heightDiff = height(root->left) - height(root->right);

    if (abs(heightDiff) > 1 || !isBalanced(root->left) || !isBalanced(root->right)) {
        return false;
    }

    return true;
}

int height(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    return max(height(root->left), height(root->right)) + 1;
}

int main() {
    int N;
    cin >> N;
    queue<Node*> nodes;

    for (int i = 0; i < N; i++) {
        int data;
        cin >> data;
        Node* node = new Node(data);
        nodes.push(node);
    }

    while (!nodes.empty()) {
        Node* parent = nodes.front();
        nodes.pop();

        int leftChild, rightChild;
        cin >> leftChild >> rightChild;

        if (leftChild != -1) {
            parent->left = nodes.front();
            nodes.push(nodes.front()->right);
        }

        if (rightChild != -1) {
            parent->right = nodes.front();
            nodes.push(nodes.front()->right);
        }

        nodes.pop();
    }

    cout << (isBalanced(nodes.front()) ? "YES" : "NO") << endl;

    return 0;
}
This C++ program first reads the number of nodes and the data of each node from the input. It then reads the left and right children of each node from the input. It uses a queue to simulate the level order traversal of the binary tree. The `isBalanced` function checks if the binary tree is height balanced. The `height` function calculates the height of the binary tree.