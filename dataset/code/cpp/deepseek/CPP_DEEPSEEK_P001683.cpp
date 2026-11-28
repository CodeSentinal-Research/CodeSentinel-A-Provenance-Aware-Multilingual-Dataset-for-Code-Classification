#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int data) : data(data), left(NULL), right(NULL) {}
};

Node* buildTree(string s) {
    if (s == "None") return NULL;
    Node* root = new Node(stoi(s));
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* node = q.front(); q.pop();
        string s1, s2;
        getline(cin, s1, ',');
        if (s1 != "None") {
            node->left = new Node(stoi(s1));
            q.push(node->left);
        }
        getline(cin, s2, ',');
        if (s2 != "None") {
            node->right = new Node(stoi(s2));
            q.push(node->right);
        }
    }
    return root;
}

int findDeepestLeftLeaf(Node* root) {
    if (root == NULL) return -1;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    int res = -1;
    while (!q.empty()) {
        Node* node = q.front().first;
        int depth = q.front().second;
        q.pop();
        if (depth % 2 == 0 && node->left == NULL && node->right == NULL) {
            res = max(res, depth);
        }
        if (node->left) q.push({node->left, depth + 1});
        if (node->right) q.push({node->right, depth + 1});
    }
    return res;
}

int main() {
    Node* root = buildTree("");
    cout << findDeepestLeftLeaf(root) << "\n";
    return 0;
}