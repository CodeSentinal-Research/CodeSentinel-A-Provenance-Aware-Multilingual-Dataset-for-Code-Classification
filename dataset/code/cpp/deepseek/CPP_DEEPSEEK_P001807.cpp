Here's the code for splitting a Binary Search Tree by a key:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void split(TreeNode* root, int X, TreeNode** first, TreeNode** second) {
    if (!root) {
        return;
    }

    if (root->val <= X) {
        split(root->right, X, second, root);
        root->right = *second;
    } else {
        split(root->left, X, root, second);
        root->left = *first;
    }
}

int main() {
    int N, X;
    cin >> N;

    TreeNode* root = NULL;
    while (N--) {
        int val;
        cin >> val;
        root = new TreeNode(val);
    }

    cin >> X;

    TreeNode* first, *second;
    split(root, X, &first, &second);

    while (first) {
        cout << first->val << " ";
        first = first->right;
    }

    cout << endl;

    while (second) {
        cout << second->val << " ";
        second = second->left;
    }

    return 0;
}

This code first reads the root of the BST and the key X. It then splits the BST into two trees: one with keys less than or equal to X and the other with keys greater than X. The first and second trees are printed, followed by a newline.