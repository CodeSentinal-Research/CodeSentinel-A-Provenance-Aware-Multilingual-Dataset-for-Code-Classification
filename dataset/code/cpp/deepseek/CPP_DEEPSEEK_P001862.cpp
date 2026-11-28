Here is the C++ code:

#include <iostream>
#include <algorithm>
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
    }
    else if (data > node->data) {
        node->right = insert(node->right, data);
    }
    return node;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int minAvgSearchCost(int keys[], int freq[], int n) {
    int i, total_freq = 0;
    for (i = 0; i < n; i++) {
        total_freq += freq[i];
    }

    Node* root = NULL;
    for (i = 0; i < n; i++) {
        int freqSum = 0;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                freqSum += freq[j];
            }
        }
        int cost = abs(total_freq / 2 - freqSum);
        root = insert(root, cost);
    }

    inorder(root);

    return 0;
}

int main() {
    int keys[] = {1, 2, 3, 4, 5};
    int freq[] = {4, 3, 2, 1, 0};
    int n = sizeof(keys) / sizeof(keys[0]);

    minAvgSearchCost(keys, freq, n);

    return 0;
}

This code first calculates the total search frequency and then for each key, it calculates the cost of the optimal search tree. The cost is calculated as the absolute difference between the total search frequency and the sum of the frequencies of the other keys. The sum of the frequencies is calculated for each key, excluding the current key. The optimal search tree is constructed by inserting each key into the optimal binary search tree with the minimum possible cost.