Here is the C++ code for your problem:

#include <iostream>
#include <queue>
#include <map>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int data) : data(data), left(NULL), right(NULL) {}
};

void topView(Node *root) {
    if (root == NULL)
        return;

    map<int, Node *> nodes;
    queue<pair<Node*, int>> q; 

    q.push({root, 0});

    while (!q.empty()) {
        pair<Node*, int> p = q.front();
        q.pop();

        Node *node = p.first;
        int hd = p.second;

        if (nodes.find(hd) == nodes.end()) {
            nodes[hd] = node;
        } else {
            nodes[hd]->left = node;
            return;
        }

        if (node->left)
            q.push({node->left, hd - 1});
        if (node->right)
            q.push({node->right, hd + 1});
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

This code first declares a Node struct and then defines the topView function. The topView function uses a map to store the nodes in each horizontal distance from the root. The queue is used to perform level order traversal of the tree. When a node is found, it is stored in the map with its horizontal distance as the key. If the horizontal distance already exists in the map, this means the node is a repeated node and we just skip it. If not, this node becomes the first node with this horizontal distance.