#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void convertToSumTree(TreeNode* root) {
    if (root == NULL) return;

    int oldVal = root->val;

    convertToSumTree(root->left);
    convertToSumTree(root->right);

    root->val = oldVal + root->left ? root->left->val : 0 + root->right ? root->right->val : 0;
}

int main() {
    int n;
    cin >> n;

    vector<int> values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    TreeNode* root = new TreeNode(values[0]);
    TreeNode* cur = root;
    for (int i = 1; i < n; i++) {
        TreeNode* child = new TreeNode(values[i]);
        if (i % 2 == 0) {
            cur->right = child;
            cur = cur->right;
        } else {
            cur->left = child;
            cur = cur->left;
        }
    }

    convertToSumTree(root);

    cur = root;
    while (cur) {
        cout << cur->val << ' ';
        if (cur->right) cur = cur->right;
        else cur = cur->left;
    }

    return 0;
}