Here is the C++ code for the problem. The code is structured as follows:

#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int val) : val(val), left(nullptr), right(nullptr) {}
};

Node* buildTree(vector<int>& inorder, vector<int>& postorder, int start, int end) {
    if (start > end) return nullptr;
    Node* root = new Node(postorder[postorder.size() - 1]);
    int k = find(inorder.begin(), inorder.end(), root->val) - inorder.begin();
    root->left = buildTree(inorder, postorder, start, k - 1);
    root->right = buildTree(inorder, postorder, k + 1, end);
    return root;
}

int findLevel(Node* root, int target, int level) {
    if (root == nullptr) return -1;
    if (root->val == target) return level;
    int left = findLevel(root->left, target, level + 1);
    if (left != -1) return left;
    return findLevel(root->right, target, level + 1);
}

void findPredecessor(Node* root, int target) {
    int level = findLevel(root, target, 0);
    if (level == -1) {
        cout << "None" << endl;
        return;
    }
    if (level == 0) {
        cout << "None" << endl;
        return;
    }
    int leftLevel = findLevel(root, target, level - 1);
    if (leftLevel == -1) {
        cout << "None" << endl;
    } else {
        cout << findLevel(root, target, leftLevel) << endl;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> inorder(n), postorder(n);
    for (int i = 0; i < n; ++i) {
        cin >> inorder[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> postorder[i];
    }
    int target;
    cin >> target;
    Node* root = buildTree(inorder, postorder, 0, n - 1);
    findPredecessor(root, target);
    return 0;
}

This code first builds the binary tree from the given inorder and postorder traversals. Then it calls the `findPredecessor` function to find the level of the target node and print the level of the predecessor of the target node.

Please note that the code assumes that the input is correctly formatted and the target node is valid.