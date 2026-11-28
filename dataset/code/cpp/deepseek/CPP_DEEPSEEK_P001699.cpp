Here is the C++ code for the problem.

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int value;
    TreeNode *left, *right;
    TreeNode(int v) : value(v), left(NULL), right(NULL) {}
};

bool isEvenOddValid(TreeNode* root) {
    if (root == NULL) return true;

    if (root->value % 2 == 0) {
        if (root->left && root->left->value % 2 == 0 ||
            root->right && root->right->value % 2 == 1) {
            return false;
        }
    } else {
        if (root->left && root->left->value % 2 == 1 ||
            root->right && root->right->value % 2 == 0) {
            return false;
        }
    }

    return isEvenOddValid(root->left) && isEvenOddValid(root->right);
}

int main() {
    int n;
    cin >> n;

    vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    vector<TreeNode*> nodes;
    for (int i = 0; i < n; ++i) {
        TreeNode* node = new TreeNode(values[i]);
        if (i == 0) {
            node->left = NULL;
            node->right = NULL;
        } else {
            if (i % 2 == 0) {
                node->left = nodes[i / 2 - 1];
            } else {
                node->right = nodes[i / 2 - 1];
            }
        }
        nodes.push_back(node);
    }

    if (isEvenOddValid(nodes[0])) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    for (int i = 0; i < nodes.size(); ++i) {
        delete nodes[i];
    }

    return 0;
}

This code first reads the number of nodes and the values of the nodes from standard input. It then constructs the binary tree from the preorder traversal of the nodes, and finally validates whether the tree satisfies the Even-Odd Tree property.