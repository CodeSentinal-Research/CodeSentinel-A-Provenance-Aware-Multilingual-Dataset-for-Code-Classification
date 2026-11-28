#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

Node* insertLevelOrder(int arr[], Node* root, int i, int n) {
    if (i < n) {
        Node* temp = newNode(arr[i]);

        temp->left = insertLevelOrder(arr, temp->left, 2 * i + 1, n);

        temp->right = insertLevelOrder(arr, temp->right, 2 * i + 2, n);

        return temp;
    }

    return root;
}

int findLowestLeaf(Node* root, int path[], int& minDepth, int depth) {
    if (root == NULL)
        return 0;

    path[depth] = root->data;

    if (root->left == NULL && root->right == NULL) {
        if (depth < minDepth) {
            minDepth = depth;
            lowestLeaf = root->data;
        }
        else if (depth == minDepth && root->data < lowestLeaf) {
            lowestLeaf = root->data;
        }
    }

    findLowestLeaf(root->left, path, minDepth, depth + 1);
    findLowestLeaf(root->right, path, minDepth, depth + 1);
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* root = newNode(arr[0]);
    root = insertLevelOrder(arr, root, 0, n);

    int path[100];
    int minDepth = INT_MAX;
    int lowestLeaf = -1;

    findLowestLeaf(root, path, minDepth, 0);

    cout << "Least leaf node is: " << lowestLeaf;

    return 0;
}