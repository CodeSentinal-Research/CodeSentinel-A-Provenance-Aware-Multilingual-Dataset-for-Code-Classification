#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inorderSameKeys(struct TreeNode* node, int* vals, int* size) {
    if (node == NULL) return;
    inorderSameKeys(node->left, vals, size);
    vals[(*size)++] = node->val;
    inorderSameKeys(node->right, vals, size);
}

bool sameKeysBST(struct TreeNode* root1, struct TreeNode* root2) {
    int arr1[10005], arr2[10005];
    int size1 = 0, size2 = 0;
    inorderSameKeys(root1, arr1, &size1);
    inorderSameKeys(root2, arr2, &size2);

    if (size1 != size2) return false;
    for (int i = 0; i < size1; i++) {
        if (arr1[i] != arr2[i]) return false;
    }
    return true;
}