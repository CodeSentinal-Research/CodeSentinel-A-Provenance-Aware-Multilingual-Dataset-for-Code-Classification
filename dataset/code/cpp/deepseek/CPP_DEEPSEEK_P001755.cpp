#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* left, * right;
    Node(int data) : data(data), left(NULL), right(NULL) {}
};

Node* buildTree(string s) {
    if (s == "None") return NULL;
    Node* root = new Node(s);
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* node = q.front(); q.pop();
        s = "";
        while (cin >> s && s != "None") {
            node->left = new Node(stoi(s));
            q.push(node->left);
            while (cin >> s && s != "None") {
                node->right = new Node(stoi(s));
                q.push(node->right);
                s = "";
            }
        }
    }
    return root;
}

void rightmostDeepestNode(Node* root) {
    if (root == NULL) return;
    queue<pair<Node*, int>> q;
    q.push({root, 1});
    int level = 0, nodeCount = 0, maxLevel = -1, maxNode = -1;
    while (!q.empty()) {
        auto nodePair = q.front(); q.pop();
        Node* node = nodePair.first;
        int currentLevel = nodePair.second;
        if (maxLevel < currentLevel) {
            maxLevel = currentLevel;
            maxNode = node->data;
            nodeCount = currentLevel;
        } else if (maxLevel == currentLevel) {
            nodeCount++;
        }
        if (node->left) q.push({node->left, currentLevel + 1});
        if (node->right) q.push({node->right, currentLevel + 1});
    }
    cout << maxNode << endl;
}

int main() {
    Node* root = buildTree("");
    rightmostDeepestNode(root);
    return 0;
}