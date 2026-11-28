#include <iostream>
#include <queue>
#include <utility>

using namespace std;

struct Node {
    int key;
    Node *left, *right;
    Node(int key) : key(key), left(NULL), right(NULL) {}
};

Node* insert(Node* root, int key) {
    if (root == NULL) {
        root = new Node(key);
    } else if (key < root->key) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    return root;
}

int closestValue(Node* root, double target) {
    int closest = root->key;
    while (root) {
        if (abs(target - closest) > abs(target - root->key)) {
            closest = root->key;
        }
        root = target < root->key ? root->left : root->right;
    }
    return closest;
}

int main() {
    int n;
    cin >> n;

    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;
        root = insert(root, key);
    }

    double target;
    cin >> target;

    cout << closestValue(root, target) << endl;

    return 0;
}
This code firstly reads the number of nodes in the binary search tree and the target value. Then it constructs the binary search tree from the given keys. Finally, it prints the closest key to the target value.