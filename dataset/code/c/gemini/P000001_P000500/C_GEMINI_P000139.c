#include <stdlib.h>
#include <stdbool.h>

int cmpInter(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    qsort(nums1, nums1Size, sizeof(int), cmpInter);
    qsort(nums2, nums2Size, sizeof(int), cmpInter);

    int* res = (int*)malloc((nums1Size < nums2Size ? nums1Size : nums2Size) * sizeof(int));
    *returnSize = 0;
    int i = 0, j = 0;

    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] == nums2[j]) {
            if (*returnSize == 0 || res[*returnSize - 1] != nums1[i]) {
                res[(*returnSize)++] = nums1[i];
            }
            i++;
            j++;
        } else if (nums1[i] < nums2[j]) {
            i++;
        } else {
            j++;
        }
    }
    return res;
}

#include <stdio.h>

int main() {
    int m, n;
    if (scanf("%d %d", &m, &n) != 2) {
        return 0;
    }

    int* nums1 = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        scanf("%d", &nums1[i]);
    }

    int* nums2 = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums2[i]);
    }

    int returnSize = 0;
    int* result = intersection(nums1, m, nums2, n, &returnSize);

    for (int i = 0; i < returnSize;
