#include <stdlib.h>
#include <string.h>
int cmpS(const void* a, const void* b) { return *(int*)a - *(int*)b; }
int* intersection(int* nums1, int m, int* nums2, int n, int* returnSize) {
    qsort(nums1, m, sizeof(int), cmpS);
    qsort(nums2, n, sizeof(int), cmpS);
    int* res = (int*)malloc((m < n ? m : n) * sizeof(int));
    int i = 0, j = 0, k = 0, prev = INT_MIN;
    while (i < m && j < n) {
        if (nums1[i] == nums2[j]) {
            if (nums1[i] != prev) { res[k++] = nums1[i]; prev = nums1[i]; }
            i++; j++;
        } else if (nums1[i] < nums2[j]) i++;
        else j++;
    }
    *returnSize = k;  // write through pointer
    return res;
}
