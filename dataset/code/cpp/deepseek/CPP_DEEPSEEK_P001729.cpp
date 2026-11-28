#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int data) {
        this->data = data;
        this->left = this->right = NULL;
    }
};

int distance(Node* root, int a, int b) {
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        Node* node = q.front().first;
        int d = q.front().second;
        q.pop();
        if (node->data == a) {
            if (node->data == b) return d;
            int da = distance(node->left, a, b);
            int db = distance(node->right, a, b);
            if (da != -1 && db != -1) return d + da + db;
            return max(da, db);
        }
        if (node->left) q.push({node->left, d + 1});
        if (node->right) q.push({node->right, d + 1});
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    int data;
    Node *root = new Node(n);
    for (int i = 0; i < n - 1; i++) {
        int p, c;
        cin >> p >> c;
        if (i == 0) {
            root->left = new Node(p);
            root->right = new Node(c);
        } else {
            if (p != -1) root->left->left = new Node(p);
            if (c != -1) root->left->right = new Node(c);
            if (p != -1) root->right->left = new Node(p);
            if (c != -1) root->right->right = new Node(c);
        }
    }
    cin >> data;
    int a = distance(root, n, data);
    root->data = n;
    int b = distance(root, n, data);
    cout << a << endl;
    return 0;
}