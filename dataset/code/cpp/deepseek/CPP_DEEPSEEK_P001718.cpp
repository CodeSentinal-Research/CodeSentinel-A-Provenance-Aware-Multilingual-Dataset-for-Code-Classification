#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

int countPaths(TreeNode* node, int k) {
    if (node == NULL) return 0;

    if (node->left == NULL && node->right == NULL) {
        return (k == node->val);
    }

    int count = 0;

    if (node->left != NULL) {
        count += countPaths(node->left, k-1);
    }
    if (node->right != NULL) {
        count += countPaths(node->right, k-1);
    }

    return count;
}

int main() {
    int n, k;
    cin >> n;

    vector<TreeNode*> nodes(n);
    for (int i = 0; i < n; i++) {
        int left, right;
        cin >> left >> right;
        TreeNode* node = new TreeNode(i+1);
        if (left != -1) {
            node->left = nodes[left-1];
        }
        if (right != -1) {
            node->right = nodes[right-1];
        }
        nodes[i] = node;
    }

    cin >> k;
    cout << countPaths(nodes[0], k) << "\n";

    return 0;
}

This program reads a binary tree and a number `k`, then counts the number of paths in the tree that consist of exactly `k` edges. The tree is represented as a list of `n` TreeNodes, where each TreeNode is represented as its index and its left and right children's indices.