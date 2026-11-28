#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inorderArr(struct TreeNode* node, int* arr, int* size) {
    if (node == NULL) return;
    inorderArr(node->left, arr, size);
    arr[(*size)++] = node->val;
    inorderArr(node->right, arr, size);
}

struct TreeNode* buildMergedBST(int* arr, int l, int r) {
    if (l > r) return NULL;
    // Calculate midpoint to prevent potential overflow
    int mid = l + (r - l) / 2;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = arr[mid];
    root->left = buildMergedBST(arr, l, mid - 1);
    root->right = buildMergedBST(arr, mid + 1, r);
    return root;
}

struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2) {
    int arr1[10005], arr2[10005], merged[20010];
    int size1 = 0, size2 = 0;
    inorderArr(root1, arr1, &size1);
    inorderArr(root2, arr2, &size2);

    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) merged[k++] = arr1[i++];
        else merged[k++] = arr2[j++];
    }
    while (i < size1) merged[k++] = arr1[i++];
    while (j < size2) merged[k++] = arr2[j++];

    return buildMergedBST(merged, 0, k - 1);
}