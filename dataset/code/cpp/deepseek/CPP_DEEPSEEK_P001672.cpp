#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void MorrisPreorderTraversal(TreeNode *root) {
    TreeNode *current, *prev, *node;
    current = root;
    while (current != NULL) {
        if (current->left == NULL) {
            cout << current->val << " ";
            current = current->right;
        } else {
            prev = current->left;
            node = current->left;
            while (prev->right != NULL && prev->right != current) {
                prev = prev->right;
            }
            if (prev->right == NULL) {
                prev->right = current;
                current = current->left;
            } else {
                prev->right = NULL;
                cout << current->val << " ";
                current = current->right;
           
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    int val;
    for (int i = 0; i < n; i++) {
        cin >> val;
    }
    TreeNode *root = new TreeNode(val);
    for (int i = 1; i < n; i++) {
        cin >> val;
        TreeNode *node = new TreeNode(val);
        if (i == 1) {
            root->left = node;
        } else {
            root->right = node;
        }
    }
    MorrisPreorderTraversal(root);
    return 0;
}