#include <iostream>
#include <unordered_set>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else {
        if (data < root->data) {
            root->left = insertNode(root->left, data);
        } else {
            root->right = insertNode(root->right, data);
        }
    }
    return root;
}

bool findTriplet(Node* root, int sum) {
    unordered_set<int> s;
    return findTripletRecursive(root, sum, s);
}

bool findTripletRecursive(Node* root, int sum, unordered_set<int>& s) {
    if (root == NULL) {
        return false;
    }
    if (s.find(sum - root->data) != s.end()) {
        cout << "YES" << endl;
        return true;
    }
    s.insert(root->data);
    return findTripletRecursive(root->left, sum, s) || findTripletRecursive(root->right, sum, s);
}

int main() {
    Node* root = NULL;
    int n, data, sum;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> data;
        root = insertNode(root, data);
    }
    cin >> sum;
    if (findTriplet(root, sum)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
This C++ code uses an unordered set to store visited nodes. It iterates through the input, inserting each node into the BST. After the input is processed, it verifies if there exists a triplet summing to the given sum in the BST.