#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inorderTarget(struct TreeNode* node, int* vals, int* size) {
    if (node == NULL) return;
    inorderTarget(node->left, vals, size);
    vals[(*size)++] = node->val;
    inorderTarget(node->right, vals, size);
}

bool findTarget(struct TreeNode* root, int k) {
    int vals[10005];
    int size = 0;
    inorderTarget(root, vals, &size);

    int l = 0, r = size - 1;
    while (l < r) {
        int sum = vals[l] + vals[r];
        if (sum == k) return true;
        if (sum < k) l++;
        else r--;
    }
    return false;
}