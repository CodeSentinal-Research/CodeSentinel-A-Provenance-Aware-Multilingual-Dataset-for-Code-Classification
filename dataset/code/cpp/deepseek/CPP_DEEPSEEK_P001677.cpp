#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* parent;
};

Node* buildTree(int n, vector<int>& children) {
    vector<Node*> tree(n);
    for (int i = 0; i < n; i++) {
        if (children[i] == -1) {
            tree[i] = nullptr;
        } else {
            tree[i] = new Node();
            tree[i]->data = i + 1;
            tree[i]->left = nullptr;
            tree[i]->right = nullptr;
            if (tree[children[i]] != nullptr) {
                tree[i]->parent = tree[children[i]];
                tree[children[i]]->right = tree[i];
            } else {
                tree[i]->parent = nullptr;
           
            }
        }
    }
    return tree[0];
}

vector<int> cousins(Node* root, int target) {
    if (root == nullptr) {
        return vector<int>(1, -1);
    }
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    vector<int> cousins;
    while (!q.empty()) {
        Node* node = q.front().first;
        int depth = q.front().second;
        q.pop();
        if (depth == target && node->left != nullptr && node->right != nullptr && node->left->data != target && node->right->data != target) {
            cousins.push_back(node->left->data);
            cousins.push_back(node->right->data);
        }
        if (node->left != nullptr) {
            q.push({node->left, depth + 1});
        }
        if (node->right != nullptr) {
            q.push({node->right, depth + 1});
        }
    }
    if (cousins.empty()) {
        cousins.push_back(-1);
    }
    return cousins;
}

int main() {
    int N;
    cin >> N;
    vector<int> children(N);
    for (int i = 0; i < N; i++) {
        cin >> children[i];
    }
    int target;
    cin >> target;
    Node* root = buildTree(N, children);
    vector<int> cousins = cousins(root, target - 1);
    for (int i = 0; i < cousins.size(); i++) {
        cout << cousins[i] << " ";
    }
    return 0;
}