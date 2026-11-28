#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

struct Node {
    int value;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(int value) : value(value) {}
};

Node* sortedArrayToBST(vector<int>& array, int start, int end) {
    if (start > end) {
        return nullptr;
    }

    int mid = (start + end) / 2;
    Node* root = new Node(array[mid]);

    root->left = sortedArrayToBST(array, start, mid - 1);
    root->right = sortedArrayToBST(array, mid + 1, end);

    return root;
}

void inorderTraversal(Node* root, vector<int>& array) {
    if (root == nullptr) {
        return;
    }

    inorderTraversal(root->left, array);
    array.push_back(root->value);
    inorderTraversal(root->right, array);
}

void convertBSTtoMinHeap(Node* root) {
    vector<int> array;
    inorderTraversal(root, array);

    root = sortedArrayToBST(array, 0, array.size() - 1);
}

int main() {
    int N;
    cin >> N;

    Node* root = nullptr;

    for (int i = 0; i < N; i++) {
        int value;
        cin >> value;

        if (i == 0) {
            root = new Node(value);
        } else {
            Node* node = new Node(value);
            if (i % 2 == 0) {
                root->right = node;
            } else {
                root->left = node;
            }
        }
    }

    convertBSTtoMinHeap(root);

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* node = q.front();
        q.pop();

        cout << node->value << " ";

        if (node->left != nullptr) {
            q.push(node->left);
        }
        if (node->right != nullptr) {
            q.push(node->right);
        }
    }

    return 0;
}