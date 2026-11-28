#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Node {
public:
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

int optimalSearchTree(int keys[], int freq[], int n, int total_freq) {
    int total_cost = 0;
    vector<int> prefix_sum(n + 1);

    for (int i = 0; i < n; i++) {
        prefix_sum[i + 1] = freq[i] + (i > 0 ? prefix_sum[i] : 0);
    }

    for (int i = 0; i < n; i++) {
        int left = (i > 0 ? prefix_sum[i] : 0);
        int right = (n - i - 1 > 0 ? prefix_sum[n - i - 1] : 0);
        int cost = abs(left - (prefix_sum[i + 1] - right));
        total_cost += cost;
   
        if (i > 0) {
            cout << "moving " << keys[i] << " to the left of " << keys[i - 1] << " with cost " << cost << endl;
        }
        else {
            cout << "adding root " << keys[i] << " with cost " << cost << endl;
        }
    }

    return total_cost;
}

void printTree(Node* root, int indent) {
    if (root != NULL) {
        printTree(root->right, indent + 4);
        cout << string(indent, ' ') << root->data << endl;
        printTree(root->left, indent + 4);
    }
}

int main() {
    int keys[] = {10, 15, 20, 25};
    int freq[] = {34, 8, 20, 35};
    int n = sizeof(keys) / sizeof(keys[0]);

    int total_freq = 100;

    cout << "Minimum cost to balance BST is " << optimalSearchTree(keys, freq, n, total_freq) << endl;

    Node* root = newNode(keys[0]);
    for (int i = 1; i < n; i++) {
        int freq_diff = freq[i];
        if (i == 1) {
            root->left = newNode(keys[1]);
            root->right = newNode(keys[2]);
            cout << "setting left child of root as " << keys[1] << " with diff " << freq_diff << endl;
            cout << "setting right child of root as " << keys[2] << " with diff " << freq_diff << endl;
        } else if (i == 2) {
            root->left->right = newNode(keys[3]);
            root->right->left = newNode(keys[3]);
            cout << "setting right child of left child of root as " << keys[3] << " with diff " << freq_diff << endl;
        } else {
            root->left->right->right = newNode(keys[i]);
        }
    }

    printTree(root, 0);

    return 0;
}