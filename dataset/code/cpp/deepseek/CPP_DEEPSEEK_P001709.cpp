Here is the C++ code to solve the problem:

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) {
        return nullptr;
    }
    int val = (t1 ? t1->val : 0) + (t2 ? t2->val : 0);
    TreeNode* node = new TreeNode(val);
    node->left = mergeTrees(t1 ? t1->left : nullptr, t2 ? t2->left : nullptr);
    node->right = mergeTrees(t1 ? t1->right : nullptr, t2 ? t2->right : nullptr);
    return node;
}

void levelOrder(TreeNode* root) {
    if (!root) {
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        cout << node->val << " ";
        if (node->left) {
            q.push(node->left);
        }
        if (node->right) {
            q.push(node->right);
        }
    }
    cout << endl;
}

int main() {
    int n1;
    cin >> n1;
    TreeNode* t1 = nullptr;
    for (int i = 0; i < n1; ++i) {
        int val;
        cin >> val;
        if (i == 0) {
            t1 = new TreeNode(val);
        } else {
            TreeNode* node = new TreeNode(val);
            if (i % 2 == 0) {
                t1->left = node;
            } else {
                t1->right = node;
            }
        }
    }

    int n2;
    cin >> n2;
    TreeNode* t2 = nullptr;
    for (int i = 0; i < n2; ++i) {
        int val;
        cin >> val;
        if (i == 0) {
            t2 = new TreeNode(val);
        } else {
            TreeNode* node = new TreeNode(val);
            if (i % 2 == 0) {
                t2->left = node;
            } else {
                t2->right = node;
            }
        }
    }

    TreeNode* merged = mergeTrees(t1, t2);

    levelOrder(merged);

    return 0;
}
This code reads the input for the two binary trees, merges them, and prints the merged tree. The `mergeTrees` function is a recursive function that merges two binary trees by creating a new node with a value of the sum of the corresponding nodes in the input trees. The `levelOrder` function is a function that prints the values of all nodes in a binary tree level by level.