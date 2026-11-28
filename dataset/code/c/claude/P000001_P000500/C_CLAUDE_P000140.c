#include <stdlib.h>
int cmpU(const void* a, const void* b) { return *(int*)a - *(int*)b; }
int* unionArrays(int* nums1, int m, int* nums2, int n, int* returnSize) {
    int* tmp = (int*)malloc((m + n) * sizeof(int));
    for (int i = 0; i < m; i++) tmp[i] = nums1[i];
    for (int i = 0; i < n; i++) tmp[m + i] = nums2[i];
    qsort(tmp, m + n, sizeof(int), cmpU);
    int* res = (int*)malloc((m + n) * sizeof(int));
    int k = 0;
    for (int i = 0; i < m + n; i++) {
        if (k == 0 || res[k-1] != tmp[i]) res[k++] = tmp[i];
    }
    free(tmp);
    *returnSize = k;  // write through pointer
    return res;
}
