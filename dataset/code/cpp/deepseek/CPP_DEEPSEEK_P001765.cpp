Here is the complete C++ solution code for the problem:

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int getHeight(TreeNode* node) {
    if (node == NULL) return 0;
    return max(getHeight(node->left), getHeight(node->right)) + 1;
}

bool checkEqualHeight(TreeNode* node, int targetHeight) {
    if (node == NULL) return true;
    if (getHeight(node) != targetHeight) return false;
    return checkEqualHeight(node->left, targetHeight) &&
           checkEqualHeight(node->right, targetHeight);
}

int main() {
    int n;
    cin >> n;
    vector<TreeNode*> nodes;
    for (int i = 0; i < n; ++i) {
        int parent, leftChild, rightChild;
        cin >> parent >> leftChild >> rightChild;
        TreeNode* parentNode = new TreeNode(parent);
        if (leftChild != -1) {
            parentNode->left = new TreeNode(leftChild);
            nodes.push_back(parentNode->left);
        }
        if (rightChild != -1) {
            parentNode->right = new TreeNode(rightChild);
            nodes.push_back(parentNode->right);
        }
    }
    if (checkEqualHeight(nodes[0], getHeight(nodes[0]))) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}

This code reads a binary tree from the standard input, and then checks whether all the paths in the tree have the same height. It uses the `getHeight` function to compute the height of each node, and the `checkEqualHeight` function to check if all nodes have the same height.