#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

int countLeafNodes(Node* node) {
    if (node == NULL)
        return 0;
    if (node->left == NULL && node->right == NULL)
        return 1;
    else
        return countLeafNodes(node->left) + countLeafNodes(node->right);
}

int main() {
    int N;
    cin >> N;
    Node* nodes[N+1];
    for (int i = 1; i <= N; i++) {
        nodes[i] = new Node();
        nodes[i]->data = i;
        nodes[i]->left = nodes[i]->right = NULL;
    }
    for (int i = 1; i < N; i++) {
        int parent, child;
        cin >> parent >> child;
        if (nodes[parent]->left == NULL)
            nodes[parent]->left = nodes[child];
        else
            nodes[parent]->right = nodes[child];
    }
    cout << countLeafNodes(nodes[1]);
    return 0;
}
This code first reads the number of nodes, then it reads the parent-child relationship of the nodes. After that, it prints the count of leaf nodes.