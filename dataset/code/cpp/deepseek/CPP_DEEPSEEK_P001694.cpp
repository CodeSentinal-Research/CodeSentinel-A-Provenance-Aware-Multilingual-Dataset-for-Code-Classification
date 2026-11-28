Here is the C++ code for the given problem:

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int val) : val(val), left(nullptr), right(nullptr) {}
};

Node* buildTree(vector<int>& nodes, int index, int n) {
    if (index >= n) {
        return nullptr;
    }
    Node* root = new Node(nodes[index]);
    root->left = buildTree(nodes, 2*index+1, n);
    root->right = buildTree(nodes, 2*index+2, n);
    return root;
}

int findDistance(Node* root, int target, unordered_map<int, int>& mp, vector<int>& parent) {
    if (root == nullptr) {
        return -1;
    }
    if (root->val == target) {
        return 0;
    }
    if (mp.find(root->val) != mp.end()) {
        return findDistance(mp[root->val], target, mp, parent);
    }
    for (int i = 0; i < 2; i++) {
        if (parent[root->val*2+i] != -1) {
            mp[root->val*2+i] = root->val;
            parent[root->val*2+i] = root->val;
            return 1 + findDistance(mp[root->val], target, mp, parent);
        }
    }
    return -1;
}

int findLeaf(Node* root, unordered_map<int, int>& mp, vector<int>& parent) {
    if (root == nullptr) {
        return -1;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return root->val;
    }
    int leftLeaf = findLeaf(root->left, mp, parent);
    if (leftLeaf != -1) {
        return leftLeaf;
    }
    int rightLeaf = findLeaf(root->right, mp, parent);
    if (rightLeaf != -1) {
        return rightLeaf;
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> nodes(n);
    for (int i = 0; i < n; i++) {
        cin >> nodes[i];
    }
    int target;
    cin >> target;
    Node* root = buildTree(nodes, 0, n);
    unordered_map<int, int> mp;
    vector<int> parent(n, -1);
    int distance = findDistance(root, target, mp, parent);
    int leaf = findLeaf(root, mp, parent);
    cout << leaf << endl;
    return 0;
}

This code first builds a tree from the given input. It then uses depth-first search to find the distance of the closest leaf node from the target node. The distances are stored in a map. Finally, it uses breadth-first search to find the leaf node with the minimum distance.