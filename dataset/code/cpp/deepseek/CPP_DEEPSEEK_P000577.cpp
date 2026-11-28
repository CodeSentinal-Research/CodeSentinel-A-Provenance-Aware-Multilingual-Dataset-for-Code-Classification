Here is the code for the given problem:

#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int data) : data(data), left(NULL), right(NULL) {}
};

vector<int> bottomView(Node *root) {
    if (root == NULL) return {};

    map<int, int> nodesAtDepth;
    queue<pair<Node*, int>> q; 

    q.push({root, 0});
    nodesAtDepth[0] = root->data;

    while (!q.empty()) {
        pair<Node*, int> nodePair = q.front();
        q.pop();

        Node* node = nodePair.first;
        int depth = nodePair.second;

        if (node->left) {
            q.push({node->left, depth-1});
            if (nodesAtDepth.find(depth-1) == nodesAtDepth.end()) {
                nodesAtDepth[depth-1] = node->left->data;
            }
        }

        if (node->right) {
            q.push({node->right, depth+1});
            if (nodesAtDepth.find(depth+1) == nodesAtDepth.end()) {
                nodesAtDepth[depth+1] = node->right->data;
            }
        }
    }

    vector<int> result;
    for (auto it = nodesAtDepth.begin(); it != nodesAtDepth.end(); ++it) {
        result.push_back(it->second);
    }

    return result;
}

int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> result = bottomView(root);

    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}

This code firstly creates the binary tree. Then it uses Breadth-First Search (BFS) to find the bottom view of the tree. The BFS technique is used to visit all the nodes in the same level and at the same time, the map stores the nodes of each level. Finally, the bottom view is found by picking the last node of each level in the map.