#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
};

Node* createNode(int val) {
    Node* node = new Node();
    node->val = val;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

Node* buildTree(int n, vector<int>& values) {
    if (n <= 0) {
        return nullptr;
    }
    Node* root = createNode(values[0]);
    queue<Node*> q;
    q.push(root);
    int i = 1;
    while (i < n) {
        Node* node = q.front();
        q.pop();
        if (i < values.size()) {
            node->left = createNode(values[i]);
            q.push(node->left);
        }
        i++;
        if (i < values.size()) {
            node->right = createNode(values[i]);
            q.push(node->right);
        }
    }
    return root;
}

int sumAtEvenLevels(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    int sum = 0;
    int level = 0;
    queue<pair<Node*, int>> q;
    q.push({root, level});
    while (!q.empty()) {
        Node* node = q.front().first;
        level = q.front().second;
        q.pop();
        if (level % 2 == 0) {
            sum += node->val;
        }
        if (node->left != nullptr) {
            q.push({node->left, level + 1});
        }
        if (node->right != nullptr) {
            q.push({node->right, level + 1});
        }
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<int> values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }
    Node* root = buildTree(n, values);
    cout << sumAtEvenLevels(root) << endl;
    return 0;
}