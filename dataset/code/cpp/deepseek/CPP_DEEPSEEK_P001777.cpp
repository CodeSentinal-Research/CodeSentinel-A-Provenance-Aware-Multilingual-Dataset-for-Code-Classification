#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
    int value;
    Node *left, *right;
    Node(int value) : value(value), left(NULL), right(NULL) {}
};

struct NodeWrapper {
    Node *node;
    int height;
    NodeWrapper(Node *node, int height) : node(node), height(height) {}
};

bool operator<(const NodeWrapper& a, const NodeWrapper& b) {
    return a.height > b.height;
}

int longestAlternatingPath(Node* root) {
    if (!root) return 0;
    priority_queue<NodeWrapper> pq;
    pq.push(NodeWrapper(root, 0));
    int res = 0;
    while (!pq.empty()) {
        NodeWrapper cur = pq.top(); pq.pop();
        int evenPath = (cur.node->left ? longestAlternatingPath(cur.node->left) : 0),
            oddPath = (cur.node->right ? longestAlternatingPath(cur.node->right) : 0);
        evenPath += (cur.node->value % 2 == 0 ? 1 : 0);
        oddPath += (cur.node->value % 2 == 1 ? 1 : 0);
        res = max(res, evenPath + oddPath - 1);
        if (cur.node->left) pq.push(NodeWrapper(cur.node->left, cur.height + 1));
        if (cur.node->right) pq.push(NodeWrapper(cur.node->right, cur.height + 1));
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }
    vector<Node*> nodes(n + 1);
    for (int i = 1; i <= n; i++) {
        nodes[i] = new Node(values[i - 1]);
        if (i * 2 <= n) {
            nodes[i]->left = nodes[i * 2];
            if (i * 2 + 1 <= n) {
                nodes[i]->right = nodes[i * 2 + 1];
            }
        }
    }
    cout << longestAlternatingPath(nodes[1]);
    return 0;
}
This code reads the input tree from the given node values, constructs the tree using the input values, and then calculates and prints the length of the longest alternating path in the tree.