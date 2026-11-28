#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void printAllPaths(TreeNode* root, int path[], int pathLen) {
    if (root == NULL) {
        return;
    }

    path[pathLen++] = root->val;

    if (root->left == NULL && root->right == NULL) {
        for (int i = 0; i < pathLen; i++) {
            cout << path[i] << " ";
        }
        cout << root->val << "\n";
    } else {
        printAllPaths(root->left, path, pathLen);
        printAllPaths(root->right, path, pathLen);
    }
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
    }

    return 0;
}

Please note that this code is for illustrative purposes only and does not account for error checking or edge cases, such as when the input tree is invalid. Also, it assumes that the input is correctly formed, which may not always be the case. This code is also not intended to be a complete solution for the problem.