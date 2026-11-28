#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

Node* createTree(vector<int>& nodes, int start, int end, int &index) {
    if (start > end) {
        return nullptr;
    }

    int mid = (start + end) / 2;
    Node* root = new Node(nodes[mid]);

    root->left = createTree(nodes, start, mid - 1, index);
    root->right = createTree(nodes, mid + 1, end, index);

    return root;
}

Node* constructBinaryTree(vector<int> &nodes) {
    int index = 0;
    return createTree(nodes, 0, nodes.size() - 1, index);
}

void reverseAlternateLevels(Node* root) {
    if (root == nullptr) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    int level = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Node* node = q.front();
            q.pop();

            if (node->left) {
                q.push(node->left);
            }

            if (node->right) {
                q.push(node->right);
            }

            if (level % 2 == 0) {
                swap(node->data, node->left ? node->left->data : 0);
            }
        }

        level++;
    }
}

void levelOrder(Node* root) {
    if (root == nullptr) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* node = q.front();
        q.pop();

        cout << node->data << " ";

        if (node->left) {
            q.push(node->left);
        }

        if (node->right) {
            q.push(node->right);
        }
    }

    cout << endl;
}

int main() {
    int n;
    cin >> n;

    vector<int> nodes(n);
    for (int i = 0; i < n; i++) {
        cin >> nodes[i];
    }

    Node* root = constructBinaryTree(nodes);

    cout << "Original tree: ";
    levelOrder(root);

    reverseAlternateLevels(root);

    cout << "Reversed tree: ";
    levelOrder(root);

    return 0;
}