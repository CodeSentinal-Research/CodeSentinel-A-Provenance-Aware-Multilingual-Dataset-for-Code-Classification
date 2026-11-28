#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inorderArrUnion(struct TreeNode* node, int* arr, int* size) {
    if (node == NULL) return;
    inorderArrUnion(node->left, arr, size);
    arr[(*size)++] = node->val;
    inorderArrUnion(node->right, arr, size);
}

int* unionBST(struct TreeNode* root1, struct TreeNode* root2, int* returnSize) {
    int arr1[10005], arr2[10005];
    int size1 = 0, size2 = 0;
    inorderArrUnion(root1, arr1, &size1);
    inorderArrUnion(root2, arr2, &size2);

    int* res = (int*)malloc(20010 * sizeof(int));
    *returnSize = 0;
    int i = 0, j = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] == arr2[j]) {
            res[(*returnSize)++] = arr1[i];
            i++;
            j++;
        } else if (arr1[i] < arr2[j]) {
            res[(*returnSize)++] = arr1[i++];
        } else {
            res[(*returnSize)++] = arr2[j++];
        }
    }
    while (i < size1) res[(*returnSize)++] = arr1[i++];
    while (j < size2) res[(*returnSize)++] = arr2[j++];

    return res;
}