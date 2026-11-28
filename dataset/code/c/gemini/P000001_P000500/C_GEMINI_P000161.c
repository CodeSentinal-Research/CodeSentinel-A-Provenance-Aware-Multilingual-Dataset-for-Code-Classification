#include <stdlib.h>

int cmpPairP000161(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** allPairs(int target, int* nums1, int n1, int* nums2, int n2, int* returnSize, int** returnColumnSizes) {
    qsort(nums1, n1, sizeof(int), cmpPairP000161);
    qsort(nums2, n2, sizeof(int), cmpPairP000161);

    int** res = (int**)malloc((n1 < n2 ? n1 : n2) * sizeof(int*));
    *returnColumnSizes = (int*)malloc((n1 < n2 ? n1 : n2) * sizeof(int));
    *returnSize = 0;

    int i = 0, j = n2 - 1;
    while (i < n1 && j >= 0) {
        int sum = nums1[i] + nums2[j];
        if (sum == target) {
            res[*returnSize] = (int*)malloc(2 * sizeof(int));
            res[*returnSize][0] = nums1[i];
            res[*returnSize][1] = nums2[j];
            (*returnColumnSizes)[*returnSize] = 2;
            (*returnSize)++;
            i++;
            j--;
        } else if (sum < target) {
            i++;
        } else {
            j--;
        }
    }
    return res;
}