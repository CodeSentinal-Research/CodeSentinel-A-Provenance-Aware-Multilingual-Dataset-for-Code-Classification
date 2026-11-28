Here's the complete C++ code:

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    int key;
    Node *left, *right;
};

Node* newNode(int key) {
    Node* temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

Node* insert(Node* node, int key) {
    if(node == NULL) return newNode(key);
    if(key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return node;
}

int median(Node* node, int &cnt, int &total) {
    if(node == NULL) return -1;
    int l = median(node->left, cnt, total);
    int r = median(node->right, cnt, total);
    if(l != -1) return l;
    if(++cnt % 2 == 0) {
        total += r;
        return total / 2;
    } else {
        return r;
    }
}

int main() {
    int N;
    cin >> N;
    Node* root = NULL;
    for(int i = 0; i < N; i++) {
        int key;
        cin >> key;
        root = insert(root, key);
    }
    int cnt = 0, total = 0;
    cout << median(root, cnt, total) << endl;
    return 0;
}

This code first reads the number of keys to be inserted. Then for each key, it inserts the key into the binary search tree. The `median` function uses a recursive approach to calculate the median of all keys in the binary search tree. The `cnt` variable is used to keep track of the current count of nodes in the binary search tree, and the `total` variable is used to keep track of the sum of all keys in the binary search tree.

This code assumes that all keys in the binary search tree are distinct. If there are duplicate keys, this code will only store one of each key, and the median will be the average of the two keys that occur most frequently.