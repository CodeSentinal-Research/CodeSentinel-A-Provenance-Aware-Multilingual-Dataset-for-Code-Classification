#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};

Node* CreateNode(int value) {
    Node* node = new Node();
    node->value = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

Node* InsertNode(Node* root, int value) {
    if (root == nullptr) {
        root = CreateNode(value);
    } else {
        if (value < root->value) {
            root->left = InsertNode(root->left, value);
        } else {
            root->right = InsertNode(root->right, value);
        }
    }
    return root;
}

Node* BuildTree(vector<int> values) {
    Node* root = nullptr;
    for (int value : values) {
        root = InsertNode(root, value);
    }
    return root;
}

void FindModes(Node* root) {
    map<int, int> counts;
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto pair = q.front();
        q.pop();
        Node* node = pair.first;
        int count = pair.second;

        if (counts.find(node->value) == counts.end()) {
            counts[node->value] = count;
        } else {
            counts[node->value] = max(counts[node->value], count);
        }

        if (node->left) {
            q.push({node->left, count + 1});
        }
        if (node->right) {
            q.push({node->right, count + 1});
        }
    }

    int maxCount = -1;
    for (auto pair : counts) {
        maxCount = max(maxCount, pair.second);
    }

    for (auto pair : counts) {
        if (pair.second == maxCount) {
            cout << pair.first << endl;
        }
    }
}

int main() {
    int N;
    cin >> N;

    vector<int> values;
    for (int i = 0; i < N; i++) {
        int value;
        cin >> value;
        values.push_back(value);
    }

    Node* root = BuildTree(values);
    FindModes(root);

    return 0;
}