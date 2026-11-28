#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left, *right;
    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

Node* buildTree(string s) {
    if (s == "x") return nullptr;
    Node* node = new Node(stoi(s));
    node->left = buildTree(s);
    node->right = buildTree(s);
    return node;
}

void leftView(Node* root) {
    if (root == nullptr) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        if (q.empty()) {
            cout << node->data << " ";
        }
        if (node->left != nullptr) {
            q.push(node->left);
        }
        if (node->right != nullptr) {
            q.push(node->right);
        }
    }
}

int main() {
    string s;
    getline(cin, s);
    int n = stoi(s);
    Node* root = buildTree(s);
    leftView(root);
    return 0;
}