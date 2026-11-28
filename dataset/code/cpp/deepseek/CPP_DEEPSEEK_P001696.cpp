#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
    char val;
    Node *left, *right;
    Node(char val) : val(val), left(nullptr), right(nullptr) {}
};

string smallestRootToLeaf(int n, vector<char> &chars, vector<vector<int>> &edges) {
    vector<Node*> nodes(chars.begin(), chars.end());
    for (auto &edge : edges) {
        if (nodes[edge[0]] == nullptr) nodes[edge[0]] = new Node(chars[edge[0]]);
        if (nodes[edge[1]] == nullptr) nodes[edge[1]] = new Node(chars[edge[1]]);
        nodes[edge[0]]->left = nodes[edge[1]];
        nodes[edge[1]]->right = nodes[edge[2]];
    }
    string smallest;
    function<void(int, string)> dfs = [&](int node, string path) {
        path.push_back(nodes[node]->val);
        if (!nodes[node]->left && !nodes[node]->right) {
            if (!smallest || path < smallest) smallest = path;
        } else {
            if (nodes[node]->left) dfs(nodes[node]->left->val, path);
            if (nodes[node]->right) dfs(nodes[node]->right->val, path);
        }
    };
    dfs(chars[0], "");
    return smallest;
}

int main() {
    int n; cin >> n;
    vector<char> chars(n);
    for (int i = 0; i < n; ++i) cin >> chars[i];
    vector<vector<int>> edges(n, vector<int>(3));
    for (int i = 0; i < n; ++i) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
        --edges[i][0];
        --edges[i][1];
        --edges[i][2];
    }
    cout << smallestRootToLeaf(n, chars, edges);
    return 0;
}
This C++ program constructs a binary tree from the input data, and then uses depth-first search to find the lexicographically smallest root-to-leaf path. The program reads the number of nodes, the characters of the nodes, and the edges of the tree from the standard input, then calls the `smallestRootToLeaf` function to find and print the smallest root-to-leaf path.