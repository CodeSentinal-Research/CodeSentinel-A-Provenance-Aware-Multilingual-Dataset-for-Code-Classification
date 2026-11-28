#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int data) : data(data), left(NULL), right(NULL) {}
};

void printLevelOrder(Node *root) {
    if (root == NULL) return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty()) {
        Node *node = q.front();
        cout << node->data << " ";
        q.pop();

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}

bool isSymmetric(Node *root1, Node *root2) {
    if (root1 == NULL && root2 == NULL) return true;
    if (root1 == NULL || root2 == NULL) return false;

    return (root1->data == root2->data)
        && isSymmetric(root1->right, root2->left)
        && isSymmetric(root1->left, root2->right);
}

Node *buildTree(vector<int> &nodes) {
    if (nodes[0] == -1) return NULL;

    Node *root = new Node(nodes[0]);
    queue<Node *> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        Node *node = q.front();
        q.pop();

        if (nodes[i] != -1) {
            node->left = new Node(nodes[i]);
            q.push(node->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != -1) {
            node->right = new Node(nodes[i]);
            q.push(node->right);
       
        }
        i++;
    }

    return root;
}

int main() {
    vector<int> nodes;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        nodes.push_back(data);
    }

    Node *root = buildTree(nodes);
    printLevelOrder(root);

    if (isSymmetric(root, root))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}