#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool dfsCheckDup(struct TreeNode* node, int* arr, int* size) {
    if (node == NULL) return false;
    for (int i = 0; i < *size; i++) {
        if (arr[i] == node->val) return true;
    }
    arr[(*size)++] = node->val;
    return dfsCheckDup(node->left, arr, size) || dfsCheckDup(node->right, arr, size);
}

bool containsDuplicate(struct TreeNode* root) {
    int arr[10005];
    int size = 0;
    return dfsCheckDup(root, arr, &size);
}