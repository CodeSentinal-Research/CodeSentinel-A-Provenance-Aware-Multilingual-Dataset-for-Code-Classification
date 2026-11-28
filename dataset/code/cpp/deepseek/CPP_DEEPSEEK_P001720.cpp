#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    int value;
    Node *left, *right;
};

int solve(Node* root, int depth) {
    if (!root) return 0;
    if (depth == 1) return root->value;
    return solve(root->left, depth - 1) + solve(root->right, depth - 1);
}

int solve(Node* root) {
    if (!root) return 0;
    queue<pair<Node*, int>> q;
    q.push({root, 1});
    int maxDepth = 0;
    while (!q.empty()) {
        Node* node = q.front().first;
        int depth = q.front().second;
        q.pop();
        maxDepth = max(maxDepth, depth);
        if (node->left) q.push({node->left, depth + 1});
        if (node->right) q.push({node->right, depth + 1});
    }
    return solve(root, maxDepth);
}

int main() {
    int n;
    cin >> n;
    vector<int> values(n);
    for (int i = 0; i < n; ++i) cin >> values[i];
    Node* root = new Node;
    root->value = values[0];
    for (int i = 1; i < n; ++i) {
        int parent = (i - 1) / 2;
        if (2 * i + 1 < n) {
            root->left = new Node;
            root->left->value = values[2 * i + 1];
            root->left->left = NULL;
            root->left->right = NULL;
            if (2 * i + 2 < n) {
                root->left->right = new Node;
                root->left->right->value = values[2 * i + 2];
                root->left->right->left = NULL;
                root->left->right->right = NULL;
            }
        }
        if (2 * i + 2 < n) {
            root->right = new Node;
            root->right->value = values[2 * i + 2];
            root->right->left = NULL;
            root->right->right = NULL;
        }
    }
    cout << solve(root);
    return 0;
}
This code first takes the number of nodes and their values from the input, then constructs a binary tree from the given values. The `solve` function then finds the sum of the nodes at the deepest level of the tree. This is done by level order traversal, starting from the root. For each node, it checks if there is a left child or a right child, and if so, adds them to the queue. It also updates the maximum depth found so far.