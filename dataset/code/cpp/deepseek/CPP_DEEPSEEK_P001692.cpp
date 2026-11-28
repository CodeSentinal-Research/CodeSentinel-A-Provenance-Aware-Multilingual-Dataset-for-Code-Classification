Here is the C++ code:

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int val) : val(val), left(NULL), right(NULL) {}
};

Node* BuildTree(vector<int>& nodes, int i, int n) {
    if (i >= n) return NULL;

    Node* root = new Node(nodes[i]);
    root->left = BuildTree(nodes, 2*i+1, n);
    root->right = BuildTree(nodes, 2*i+2, n);

    return root;
}

pair<int, int> LongestConsecutivePath(Node* root) {
    if (root == NULL) return make_pair(0, 0);

    pair<int, int> left = LongestConsecutivePath(root->left);
    pair<int, int> right = LongestConsecutivePath(root->right);

    int singlePath = root->val;
    int maxSinglePath = max(max(left.first, right.first), singlePath);

    int doublePath = root->val + left.first + right.first;
    int maxDoublePath = max(max(maxSinglePath, doublePath), left.second + right.second + root->val);

    return make_pair(maxSinglePath, maxDoublePath);
}

int main() {
    int n;
    cin >> n;

    vector<int> nodes(n);
    for (int i = 0; i < n; ++i) {
        cin >> nodes[i];
    }

    Node* root = BuildTree(nodes, 0, n);

    pair<int, int> result = LongestConsecutivePath(root);

    cout << max(result.first, result.second) << endl;

    return 0;
}

This code first builds the binary tree from the provided node values. It then calls the `LongestConsecutivePath` function which calculates the length of the longest consecutive path in the binary tree.