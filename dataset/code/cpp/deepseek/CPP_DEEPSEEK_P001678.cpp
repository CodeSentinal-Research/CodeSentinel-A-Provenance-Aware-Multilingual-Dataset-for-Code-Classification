#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* node = new Node;
    node->value = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

Node* insertNode(Node* root, int value) {
    if (root == nullptr) {
        root = createNode(value);
    } else {
        if (root->left == nullptr) {
            root->left = createNode(value);
        } else {
            root->right = createNode(value);
        }
    }
    return root;
}

bool findCousins(Node* root, int x, int y) {
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* node = q.front();
        q.pop();

        if (node->left && node->left->value == x && node->right && node->right->value == y) {
            if (node->left->value != y && node->right->value != y) {
                return true;
            }
        }

        if (node->left) {
            q.push(node->left);
        }
        if (node->right) {
            q.push(node->right);
        }
    }

    return false;
}

int main() {
    int N;
    cin >> N;

    Node* root = nullptr;
    for (int i = 0; i < N; i++) {
        int value;
        cin >> value;
        root = insertNode(root, value);
    }

    int x, y;
    cin >> x >> y;

    bool result = findCousins(root, x, y);
    if (result) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
This C++ solution first reads the number of nodes and the values of the nodes from the standard input. It then reads the values of the two nodes to be found as cousins. The `findCousins` function is then called, passing the root node and the two values. If the nodes are found as cousins, the function returns true, otherwise it returns false. The result is then printed to the standard output.