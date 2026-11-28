#include <iostream>
#include <queue>
#include <map>
#include <utility>

using namespace std;

struct Node {
    int data;
    Node* left, *right;
    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

void topView(Node* root) {
    if (root == nullptr) return;

    map<int, pair<int, Node*>> nodes;
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        pair<Node*, int> p = q.front(); q.pop();

        if (nodes.find(p.second) == nodes.end()) {
            nodes[p.second] = make_pair(p.first->data, p.first);
        } else {
            if (p.first->data < nodes[p.second].first) {
                nodes[p.second].first = p.first->data;
            }
        }

        if (p.first->left) q.push({p.first->left, p.second - 1});
         
        if (p.first->right) q.push({p.first->right, p.second + 1});
    }

    for (auto it = nodes.begin(); it != nodes.end(); it++) {
        cout << it->second.first << " ";
    }
}

int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    topView(root);

    return 0;
}