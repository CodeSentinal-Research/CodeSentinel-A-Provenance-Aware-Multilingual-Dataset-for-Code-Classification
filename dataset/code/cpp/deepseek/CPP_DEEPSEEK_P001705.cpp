Here is the C++ code for the problem:

#include <iostream>
#include <vector>
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

Node* buildTree(vector<int> &nodes, int start, int end) {
    if (start > end) {
        return nullptr;
    }

    int mid = (start + end) / 2;
    Node* root = new Node(nodes[mid]);
    root->left = buildTree(nodes, start, mid - 1);
    root->right = buildTree(nodes, mid + 1, end);
    return root;
}

int maxWidth(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    queue<pair<Node*, int>> q;
    q.push({root, 0});
    int currWidth = 0;
    int minIndex = 0;
    int maxWidth = 0;

    while (!q.empty()) {
        int count = q.size();
        currWidth = q.back().second - q.front().second + 1;
        maxWidth = max(maxWidth, currWidth);

        for (int i = 0; i < count; i++) {
            Node* node = q.front().first;
            int index = q.front().second;
            q.pop();

            if (node->left != nullptr) {
                q.push({node->left, 2 * index + 1});
            }
            if (node->right != nullptr) {
                q.push({node->right, 2 * index + 2});
           
            }
        }
    }
    return maxWidth;
}

int main() {
    vector<int> nodes = {1, 2, 3, 4, 5, 6, 7};
    Node* root = buildTree(nodes, 0, nodes.size() - 1);
    cout << "Maximum Width: " << maxWidth(root) << endl;
    return 0;
}

This code first builds the binary tree from the given array of nodes. Then it computes the maximum width of the binary tree. The maximum width is the maximum difference between the indexes of any two nodes in the tree.