#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int value;
    Node *left, *right;
    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

Node* buildTree(vector<int>& inorder, vector<int>& postorder, int start, int end, int& index) {
    if (start > end) {
        return nullptr;
    }

    Node* node = new Node(postorder[index--]);

    if (start == end) {
        return node;
    }

    int inIndex = find(inorder.begin(), inorder.end(), node->value) - inorder.begin();
    node->right = buildTree(inorder, postorder, inIndex + 1, end, index);
    node->left = buildTree(inorder, postorder, start, inIndex - 1, index);

    return node;
}

Node* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int index = (int)postorder.size() - 1;
    return buildTree(inorder, postorder, 0, inorder.size() - 1, index);
}

int findCentroid(Node* root) {
    if (!root->left && !root->right) {
        return root->value;
    }

    if (!root->right) {
        return findCentroid(root->left);
    }

    if (!root->left) {
        return findCentroid(root->right);
    }

    return root->value;
}

int main() {
    int n;
    cin >> n;

    vector<int> inorder(n), postorder(n);
    for (int& value : inorder) {
        cin >> value;
    }
    for (int& value : postorder) {
        cin >> value;
    }

    Node* root = buildTree(inorder, postorder);
    cout << findCentroid(root) << '\n';

    return 0;
}