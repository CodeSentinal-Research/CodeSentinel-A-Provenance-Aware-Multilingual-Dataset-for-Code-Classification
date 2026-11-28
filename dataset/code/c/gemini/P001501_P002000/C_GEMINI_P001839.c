#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inorderTriplet(struct TreeNode* node, int* vals, int* size) {
    if (node == NULL) return;
    inorderTriplet(node->left, vals, size);
    vals[(*size)++] = node->val;
    inorderTriplet(node->right, vals, size);
}

bool findTriplet(struct TreeNode* root, int target) {
    int vals[10005];
    int size = 0;
    inorderTriplet(root, vals, &size);

    for (int i = 0; i < size - 2; i++) {
        int l = i + 1, r = size - 1;
        while (l < r) {
            int sum = vals[i] + vals[l] + vals[r];
            if (sum == target) return true;
            else if (sum < target) l++;
            else r--;
        }
    }
    return false;
}