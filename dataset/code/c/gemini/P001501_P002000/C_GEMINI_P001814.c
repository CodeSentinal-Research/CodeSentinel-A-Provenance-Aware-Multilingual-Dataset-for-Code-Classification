#include <stdlib.h>
#include <limits.h>
#include <math.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inorderPair(struct TreeNode* node, int* arr, int* size) {
    if (node == NULL) return;
    inorderPair(node->left, arr, size);
    arr[(*size)++] = node->val;
    inorderPair(node->right, arr, size);
}

int* findClosestPair(struct TreeNode* root1, struct TreeNode* root2, int target, int* returnSize) {
    *returnSize = 2;
    int* res = (int*)malloc(2 * sizeof(int));
    int arr1[10005], arr2[10005];
    int size1 = 0, size2 = 0;
    inorderPair(root1, arr1, &size1);
    inorderPair(root2, arr2, &size2);

    int i = 0, j = size2 - 1;
    long long bestDiff = LLONG_MAX;
    res[0] = arr1[0]; res[1] = arr2[size2 - 1];

    while (i < size1 && j >= 0) {
        int curSum = arr1[i] + arr2[j];
        long long diff = llabs((long long)curSum - target);
        if (diff < bestDiff) {
            bestDiff = diff;
            res[0] = arr1[i];
            res[1] = arr2[j];
        }
        if (curSum < target) i++;
        else j--;
    }
    return res;
}