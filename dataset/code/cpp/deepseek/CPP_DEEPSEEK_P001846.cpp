Here is the C++ code for the problem:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool canConvert(TreeNode* root) {
    if (root == NULL) return true;
    if (root->left == NULL && root->right == NULL) return true;
    if (root->left == NULL || root->right == NULL) return false;

    return (canConvert(root->left) && canConvert(root->right) && (root->val == root->left->val + 1) && (root->val == root->right->val - 1));
}

int main() {
    int N;
    cin >> N;
    vector<int> nodes(N);
    for (int i = 0; i < N; i++) {
        cin >> nodes[i];
    }

    TreeNode* root = constructMaximumBinaryTree(nodes);

    if (canConvert(root)) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}

This C++ program reads the number of nodes and the values of the nodes from the input, then constructs a binary tree from the given nodes. It then checks if it's possible to convert this tree into a Binary Search Tree using only left and right rotations. If possible, it prints "YES", otherwise it prints "NO".