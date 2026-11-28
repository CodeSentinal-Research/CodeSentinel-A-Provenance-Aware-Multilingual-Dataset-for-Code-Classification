Here is the C++ code to solve the problem:

#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int val) : val(val), left(nullptr), right(nullptr) {}
};

void printMaxAtEachLevel(Node* root) {
    if (root == nullptr) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int maxVal = INT_MIN;
        for (int i = q.size(); i > 0; --i) {
            Node* node = q.front();
            q.pop();

            maxVal = max(maxVal, node->val);

            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
           
            }
        }
        cout << maxVal << endl;
    }
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int value;
        cin >> value;

        Node* node = new Node(value);

        if (i > 0) {
            Node* parent = nullptr;
            cin >> parent;

            if (parent) {
                if (parent->left) {
                    node->left = parent->left;
                } else {
                    node->left = parent->right;
                }
            }

            if (i < N - 1) {
                cin >> parent;

                if (parent) {
                    if (parent->left) {
                        node->right = parent->left;
                    } else {
                        node->right = parent->right;
                    }
                }
            }
        }

        if (i == 0) {
            root = node;
        }
    }

    printMaxAtEachLevel(root);

    return 0;
}

This code reads the input, constructs the binary tree, and then prints the maximum node value at each level. The code assumes that the input is correct and follows the given constraints.