#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inorderArrInter(struct TreeNode* node, int* arr, int* size) {
    if (node == NULL) return;
    inorderArrInter(node->left, arr, size);
    arr[(*size)++] = node->val;
    inorderArrInter(node->right, arr, size);
}

int* intersectionBST(struct TreeNode* root1, struct TreeNode* root2, int* returnSize) {
    int arr1[10005], arr2[10005];
    int size1 = 0, size2 = 0;
    inorderArrInter(root1, arr1, &size1);
    inorderArrInter(root2, arr2, &size2);

    int* res = (int*)malloc(10005 * sizeof(int));
    *returnSize = 0;
    int i = 0, j = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] == arr2[j]) {
            res[(*returnSize)++] = arr1[i];
            i++;
            j++;
        } else if (arr1[i] < arr2[j]) {
            i++;
        } else {
            j++;
        }
    }
    return res;
}