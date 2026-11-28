#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
};

Node *newNode(int item) {
    Node *temp = new Node;
    temp->key = item;
    temp->left = temp->right = nullptr;
    return temp;
}

Node *insert(Node *node, int key) {
    if (node == nullptr) return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}

Node *findMin(Node *node) {
    Node *current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

Node *find(Node *root, int key) {
    if (root == nullptr || root->key == key)
        return root;
    if (root->key < key)
        return find(root->right, key);
    return find(root->left, key);
}

Node *lowestCommonAncestor(Node *root, int a, int b, int c) {
    if (root == nullptr)
        return nullptr;
    if (root->key == a || root->key == b || root->key == c)
        return root;
    Node *left = lowestCommonAncestor(root->left, a, b, c);
    Node *right = lowestCommonAncestor(root->right, a, b, c);
    if (left != nullptr && right != nullptr)
        return root;
    return (left != nullptr) ? left : right;
}

int main() {
    int n;
    cin >> n;
    Node *root = nullptr;
    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;
        root = insert(root, key);
    }
    int a, b, c;
    cin >> a >> b >> c;
    Node *result = lowestCommonAncestor(root, a, b, c);
    cout << result->key;
    return 0;
}