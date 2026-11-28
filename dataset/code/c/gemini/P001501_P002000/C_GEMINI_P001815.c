#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inorderArrCount(struct TreeNode* node, int* arr, int* size) {
    if (node == NULL) return;
    inorderArrCount(node->left, arr, size);
    arr[(*size)++] = node->val;
    inorderArrCount(node->right, arr, size);
}

int countPairs(struct TreeNode* root1, struct TreeNode* root2, int target) {
    int arr1[10005], arr2[10005];
    int size1 = 0, size2 = 0;
    inorderArrCount(root1, arr1, &size1);
    inorderArrCount(root2, arr2, &size2);

    int i = 0, j = size2 - 1;
    int count = 0;

    while (i < size1 && j >= 0) {
        int curSum = arr1[i] + arr2[j];
        if (curSum == target) {
            count++;
            i++;
            j--;
        } else if (curSum < target) {
            i++;
        } else {
            j--;
        }
    }
    return count;
}