Here is the C++ code for the problem. It uses a tree structure for handling the tree and a map to store the parent node of each node. It then performs the LCA query by finding the nearest common ancestor.

#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct Node {
    int id;
    Node* parent;
    vector<Node*> children;

    Node(int id, Node* parent) : id(id), parent(parent) {}
};

Node* createTree(int n, vector<int>* parents) {
    vector<Node*> nodes;
    for (int i = 0; i < n; i++) {
        nodes.push_back(new Node(i, parents[i] ? new Node(parents[i]->id, nodes[parents[i]->id]) : nullptr));
    }
    for (int i = 0; i < n; i++) {
        if (nodes[i]->parent) {
            nodes[i->parent]->children.push_back(nodes[i]);
        }
    }
    return nodes[0];
}

int findLCA(Node* node1, Node* node2, Node* root) {
    if (node1 == root) {
        return root->id;
    }
    if (node2 == root) {
        return root->id;
    }
    if (node1->parent) {
        int a = findLCA(node1->parent, node2, root);
        if (a != -1) {
            return a;
        }
    }
    if (node2->parent) {
        int a = findLCA(node2->parent, node1, root);
        if (a != -1) {
            return a;
        }
    }
    return -1;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> parents(n);
    for (int i = 0; i < n - 1; i++) {
        int parent, child;
        cin >> parent >> child;
        parents[child] = parent;
    }
    Node* root = createTree(n, &parents);
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << findLCA(root, root->children[a], root) << endl;
    }
    return 0;
}

This code assumes that the first line of input contains the number of nodes and the number of queries, followed by the tree's edges. The parent of each node is stored in a vector. The LCA is found by using a Depth-First Search (DFS) approach.

Please note that this code assumes that the input is a valid tree. It does not handle the case where the parent node of a node is not in the valid range (i.e., it is negative or greater than the number of nodes). You may want to add additional checks based on your specific use case.