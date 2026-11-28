#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

int increasingCount = 0, decreasingCount = 0;

void countPaths(Node* root, bool isIncreasing) {
    if (root == NULL) {
        return;
    }

    if (isIncreasing && root->data >= root->left->data && root->data >= root->right->data) {
        increasingCount++;
    }
    else if (!isIncreasing && root->data <= root->left->data && root->data <= root->right->data) {
        decreasingCount++;
    }

    countPaths(root->left, root->data >= root->left->data);
    countPaths(root->right, root->data <= root->right->data);
}

int main() {
    int N;
    cin >> N;

    Node* nodes[N];
    for (int i = 0; i < N; i++) {
        nodes[i] = new Node();
        cin >> nodes[i]->data;
        nodes[i]->left = nodes[i]->right = NULL;
    }

    for (int i = 0; i < N - 1; i++) {
        nodes[i]->left = nodes[i + 1];
        nodes[i + 1]->right = nodes[i];
    }

    Node* root = nodes[0];
    countPaths(root, true);

    cout << increasingCount << endl;

    increasingCount = decreasingCount = 0;

    countPaths(root, false);

    cout << decreasingCount << endl;

    return 0;
}
This code first reads the number of nodes and the data for each node. Then it creates a binary tree from these nodes. The `countPaths` function is used to count the number of root-to-leaf paths whose values are strictly increasing or strictly decreasing.