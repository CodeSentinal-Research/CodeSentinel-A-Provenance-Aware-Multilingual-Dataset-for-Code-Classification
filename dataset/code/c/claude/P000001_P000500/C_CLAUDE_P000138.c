#include <stdlib.h>
int* mergeSorted(int* a, int m, int* b, int n, int* returnSize) {
    *returnSize = m + n;  // write through pointer
    int* res = (int*)malloc((m + n) * sizeof(int));
    int i = 0, j = 0, k = 0;
    while (i < m && j < n) res[k++] = (a[i] <= b[j]) ? a[i++] : b[j++];
    while (i < m) res[k++] = a[i++];
    while (j < n) res[k++] = b[j++];
    return res;
}
