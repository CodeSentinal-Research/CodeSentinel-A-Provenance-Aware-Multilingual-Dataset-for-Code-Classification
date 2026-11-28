#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void replaceNodes(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    int level = -1;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        pair<TreeNode*, int> node = q.front();
        q.pop();

        if (node.second > level) {
            level = node.second;
        }

        if (node.first->left) {
            q.push({node.first->left, node.second + 1});
        }

        if (node.first->right) {
            q.push({node.first->right, node.second + 1});
        }

        node.first->val += q.back().first->val;
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    TreeNode* root = new TreeNode(values[0]);
    for (int i = 1; i < n; ++i) {
        TreeNode* parent = root;
        while (true) {
            if (values[i] < parent->val) {
                if (parent->left) {
                    parent = parent->left;
                } else {
                    parent->left = new TreeNode(values[i]);
                    break;
                }
            } else {
                if (parent->right) {
                    parent = parent->right;
                } else {
                    parent->right = new TreeNode(values[i]);
                    break;
                }
            }
        }
    }

    replaceNodes(root);

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        cout << node->val << ' ';

        if (node->left) {
            q.push(node->left);
        }

        if (node->right) {
            q.push(node->right);
        }
    }

    return 0;
}