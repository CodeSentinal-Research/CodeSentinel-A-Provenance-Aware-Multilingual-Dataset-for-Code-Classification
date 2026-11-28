#include <stdlib.h>

int cmpUnion(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* unionArrays(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int total = nums1Size + nums2Size;
    int* all = (int*)malloc(total * sizeof(int));
    for (int i = 0; i < nums1Size; i++) all[i] = nums1[i];
    for (int i = 0; i < nums2Size; i++) all[nums1Size + i] = nums2[i];

    qsort(all, total, sizeof(int), cmpUnion);

    int* res = (int*)malloc(total * sizeof(int));
    *returnSize = 0;
    for (int i = 0; i < total; i++) {
        if (*returnSize == 0 || res[*returnSize - 1] != all[i]) {
            res[(*returnSize)++] = all[i];
        }
    }
    free(all);
    return res;
}